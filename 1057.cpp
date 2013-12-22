#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<sstream>
#include<set>
#include<cstdio>

using namespace std;

vector<int> it;
multiset<int,less<int> > mins,maxs;
multiset<int>::iterator ii,ss;

int main(void)
{
  int n;
  scanf("%d",&n);
  char str[20];
  int i;
  int medium=-1;
  for(i=0;i<n;i++)
  {
    scanf("%s",str);
    if(strcmp(str,"Pop")==0)
    {
      if(it.empty())
        puts("Invalid");
      else
      {
                int tt=it[it.size()-1];
                it.pop_back();
                printf("%d\n",tt);
                if(tt<=medium)
                {
                    ii=mins.find(tt);
                    mins.erase(ii);
                }
                else
                {
                    ii=maxs.find(tt);
                    maxs.erase(ii);
                }
                /*for(ii=mins.begin();ii!=mins.end();ii++)
                    cout<<*ii<<" ";
                cout<<"min"<<mins.size()<<endl;
                for(ii=maxs.begin();ii!=maxs.end();ii++)
                    cout<<*ii<<" ";
                cout<<"max"<<maxs.size()<<endl;*/
                if(mins.size()>maxs.size()+1)
                {
                    ii=mins.end();
                    ii--;
                    ss=ii;
                    ss--;
                    maxs.insert(*ii);
                    mins.erase(ii);
                    medium=*ss;
                }
                else if(mins.size()<maxs.size())
                {
                    ii=maxs.begin();
                    medium=*ii;
                    mins.insert(*ii);
                    maxs.erase(ii);
                }
                else if(it.size()!=0)
                {
                    ii=mins.end();
                    ii--;
                    medium=*ii;
                }
                /*for(ii=mins.begin();ii!=mins.end();ii++)
                    cout<<*ii<<" ";
                cout<<"min"<<endl;
                for(ii=maxs.begin();ii!=maxs.end();ii++)
                    cout<<*ii<<" ";
                cout<<"max"<<endl;*/
      }
    }
    else if(strcmp(str,"PeekMedian")==0)
    {
      if(it.empty())
        puts("Invalid");
      else
        printf("%d\n",medium);
    }
    else if(strcmp(str,"Push")==0)
    {
      //string s;
      int a;
      scanf("%d",&a);
      //s=str.substr(5);
      //stringstream ss;
      //ss<<s;
      //int a;
      //ss>>a;
      it.push_back(a);
      if(it.size()==1)
      {
            mins.insert(a);
            medium=a;
            continue;
    }
      else if(a<=medium)
            mins.insert(a);
      else
            maxs.insert(a);
            /*for(ii=mins.begin();ii!=mins.end();ii++)
                cout<<*ii<<" ";
            cout<<"min"<<mins.size()<<endl;
            for(ii=maxs.begin();ii!=maxs.end();ii++)
                cout<<*ii<<" ";
            cout<<"max"<<maxs.size()<<endl;*/
            if(mins.size()>maxs.size()+1)
            {
                ii=mins.end();
                ii--;
                ss=ii;
                ss--;
                maxs.insert(*ii);
                mins.erase(ii);
                medium=*ss;
            }
            else if(mins.size()<maxs.size())
            {
                ii=maxs.begin();
                medium=*ii;
                mins.insert(*ii);
                maxs.erase(ii);
            }
            else if(it.size()!=0)
            {
                ii=mins.end();
                ii--;
                medium=*ii;
            }
            /*for(ii=mins.begin();ii!=mins.end();ii++)
                cout<<*ii<<" ";
            cout<<"min"<<endl;
            for(ii=maxs.begin();ii!=maxs.end();ii++)
                cout<<*ii<<" ";
            cout<<"max"<<endl;*/
    }
    else
            cout<<"Invalid"<<endl;
  }
  return 0;
}
