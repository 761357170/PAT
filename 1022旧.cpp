#include<iostream>
#include<set>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
#include<list>
#include<cstdio>
#include<cstdlib>

using namespace std;

int countblank(char* s)
{
    int t=0;
    for(int i=0;i<strlen(s);i++)
        if(s[i]==' ')
           t++;
    return t;
}

int main(void)
{
    typedef pair<int,int> Int_Pair;
    typedef pair<string,int> S_Pair;
    int n,m,i,j,id;
    char tmp[100];
    multimap<int,int,less<int> >  year;
    multimap<int,int>::iterator iti;
    multimap<string,int,less<string> > title,writer,keywords,press;
    multimap<string,int>::iterator its;
    list<int> no;
    list<int>::iterator it;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>id;
        getchar();
        gets(tmp);
        string s(tmp);
        title.insert(S_Pair(s,id));
        gets(tmp);
        string st(tmp);
        writer.insert(S_Pair(st,id));
        gets(tmp);
        int t=countblank(tmp);
        if(t==0)
        {
            string str(tmp);
            keywords.insert(S_Pair(str,id));
        }
        else if(t==1)
        {
            char s1[20],s2[20];
            sscanf(tmp,"%s %s",s1,s2);
            string str1(s1),str2(s2);
            keywords.insert(S_Pair(str1,id));
            keywords.insert(S_Pair(str2,id));
        }
        else if(t==2)
        {
            char s1[20],s2[20],s3[20];
            sscanf(tmp,"%s %s %s",s1,s2,s3);
            string str1(s1),str2(s2),str3(s3);
            keywords.insert(S_Pair(str1,id));
            keywords.insert(S_Pair(str2,id));
            keywords.insert(S_Pair(str3,id));
        }
        else if(t==3)
        {
            char s1[20],s2[20],s3[20],s4[20];
            sscanf(tmp,"%s %s %s %s",s1,s2,s3,s4);
            string str1(s1),str2(s2),str3(s3),str4(s4);
            keywords.insert(S_Pair(str1,id));
            keywords.insert(S_Pair(str2,id));
            keywords.insert(S_Pair(str3,id));
            keywords.insert(S_Pair(str4,id));
        }
        else
        {
            char s1[20],s2[20],s3[20],s4[20],s5[20];
            sscanf(tmp,"%s %s %s %s %s",s1,s2,s3,s4,s5);
            string str1(s1),str2(s2),str3(s3),str4(s4),str5(s5);
            keywords.insert(S_Pair(str1,id));
            keywords.insert(S_Pair(str2,id));
            keywords.insert(S_Pair(str3,id));
            keywords.insert(S_Pair(str4,id));
            keywords.insert(S_Pair(str5,id));
        }
        gets(tmp);
        string a(tmp);
        press.insert(S_Pair(a,id));
        cin>>j;
        year.insert(Int_Pair(j,id));
    }
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>j;
        getchar();
        getchar();
        if(j==1)
        {
            gets(tmp);
            string b(tmp);
            cout<<j<<":"<<" "<<b<<endl;
            its=title.find(b);
            no.clear();
            while(its!=title.end())
            {
                no.push_back(its->second);
                title.erase(its);
                its=title.find(b);
            }
            if(no.empty())
            {
                cout<<"Not Found"<<endl;
                continue;
            }
            no.sort();
            for(it=no.begin();it!=no.end();it++)
                printf("%07d\n",*it);
        }
        else if(j==2)
        {
            gets(tmp);
            string c(tmp);
            cout<<j<<":"<<" "<<c<<endl;
            its=writer.find(c);
            no.clear();
            while(its!=writer.end())
            {
                no.push_back(its->second);
                writer.erase(its);
                its=writer.find(c);
            }
            if(no.empty())
            {
                cout<<"Not Found"<<endl;
                continue;
            }
            no.sort();
            for(it=no.begin();it!=no.end();it++)
                printf("%07d\n",*it);
        }
        else if(j==3)
        {
            gets(tmp);
            string c(tmp);
            cout<<j<<":"<<" "<<c<<endl;
            its=keywords.find(c);
            no.clear();
            while(its!=keywords.end())
            {
                no.push_back(its->second);
                keywords.erase(its);
                its=keywords.find(c);
            }
            if(no.empty())
            {
                cout<<"Not Found"<<endl;
                continue;
            }
            no.sort();
            for(it=no.begin();it!=no.end();it++)
               printf("%07d\n",*it);
        }
        else if(j==4)
        {
            gets(tmp);
            string c(tmp);
            cout<<j<<":"<<" "<<c<<endl;
            its=press.find(c);
            no.clear();
            while(its!=press.end())
            {
                no.push_back(its->second);
                press.erase(its);
                its=press.find(c);
            }
            if(no.empty())
            {
                cout<<"Not Found"<<endl;
                continue;
            }
            no.sort();
            for(it=no.begin();it!=no.end();it++)
                printf("%07d\n",*it);
        }
        else
        {
            int y;
            cin>>y;
            cout<<j<<":"<<" ";
            printf("%04d\n",y);
            iti=year.find(y);
            no.clear();
            while(iti!=year.end())
            {
                no.push_back(iti->second);
                year.erase(iti);
                iti=year.find(y);
            }
            if(no.empty())
            {
                cout<<"Not Found"<<endl;
                continue;
            }
            no.sort();
            for(it=no.begin();it!=no.end();it++)
                printf("%07d\n",*it);
        }
    }
    return 0;
}
