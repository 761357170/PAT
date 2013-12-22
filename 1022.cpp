#include<iostream>
#include<set>
#include<list>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
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
    list<int> title[10000],writer[10000],press[1000],year[3001],keywords[1000];
    list<int> ::iterator it;
    map<string,int,less<string> > t,w,p,k;
    map<string,int>::iterator its;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>id;
        getchar();
        gets(tmp);
        string s(tmp);
        if(t.empty())
            t.insert(S_Pair(s,t.size()));
        its=t.find(s);
        if(its==t.end())
        {
            t.insert(S_Pair(s,t.size()));
            its=t.find(s);
        }
        title[its->second].push_back(id);
        gets(tmp);
        string st(tmp);
        if(w.empty())
            w.insert(S_Pair(st,w.size()));
        its=w.find(st);
        if(its==w.end())
        {
            w.insert(S_Pair(st,w.size()));
            its=w.find(st);
        }
        writer[its->second].push_back(id);
        gets(tmp);
        int tp=countblank(tmp);
        if(tp==0)
        {
            string str(tmp);
            if(k.empty())
                k.insert(S_Pair(str,k.size()));
            its=k.find(str);
            if(its==k.end())
            {
                k.insert(S_Pair(str,k.size()));
                its=k.find(str);
            }
            keywords[its->second].push_back(id);
        }
        else if(tp==1)
        {
            char s1[20],s2[20];
            sscanf(tmp,"%s %s",s1,s2);
            string str1(s1),str2(s2);
            if(k.empty())
                k.insert(S_Pair(str1,k.size()));
            its=k.find(str1);                   //1
            if(its==k.end())
            {
                k.insert(S_Pair(str1,k.size()));
                its=k.find(str1);
            }
            keywords[its->second].push_back(id);
            its=k.find(str2);                  //2
            if(its==k.end())
            {
                k.insert(S_Pair(str2,k.size()));
                its=k.find(str2);
            }
            keywords[its->second].push_back(id);
        }
        else if(tp==2)
        {
            char s1[20],s2[20],s3[20];
            sscanf(tmp,"%s %s %s",s1,s2,s3);
            string str1(s1),str2(s2),str3(s3);
            if(k.empty())
                k.insert(S_Pair(str1,k.size()));
            its=k.find(str1);                   //1
            if(its==k.end())
            {
                k.insert(S_Pair(str1,k.size()));
                its=k.find(str1);
            }
            keywords[its->second].push_back(id);
            its=k.find(str2);                  //2
            if(its==k.end())
            {
                k.insert(S_Pair(str2,k.size()));
                its=k.find(str2);
            }
            keywords[its->second].push_back(id);
            its=k.find(str3);                  //3
            if(its==k.end())
            {
                k.insert(S_Pair(str3,k.size()));
                its=k.find(str3);
            }
            keywords[its->second].push_back(id);
        }
        else if(tp==3)
        {
            char s1[20],s2[20],s3[20],s4[20];
            sscanf(tmp,"%s %s %s %s",s1,s2,s3,s4);
            string str1(s1),str2(s2),str3(s3),str4(s4);
            if(k.empty())
                k.insert(S_Pair(str1,k.size()));
            its=k.find(str1);                   //1
            if(its==k.end())
            {
                k.insert(S_Pair(str1,k.size()));
                its=k.find(str1);
            }
            keywords[its->second].push_back(id);
            its=k.find(str2);                  //2
            if(its==k.end())
            {
                k.insert(S_Pair(str2,k.size()));
                its=k.find(str2);
            }
            keywords[its->second].push_back(id);
            its=k.find(str3);                  //3
            if(its==k.end())
            {
                k.insert(S_Pair(str3,k.size()));
                its=k.find(str3);
            }
            keywords[its->second].push_back(id);
            its=k.find(str4);                  //4
            if(its==k.end())
            {
                k.insert(S_Pair(str4,k.size()));
                its=k.find(str4);
            }
            keywords[its->second].push_back(id);
        }
        else
        {
            char s1[20],s2[20],s3[20],s4[20],s5[20];
            sscanf(tmp,"%s %s %s %s %s",s1,s2,s3,s4,s5);
            string str1(s1),str2(s2),str3(s3),str4(s4),str5(s5);
            if(k.empty())
                k.insert(S_Pair(str1,k.size()));
            its=k.find(str1);                   //1
            if(its==k.end())
            {
                k.insert(S_Pair(str1,k.size()));
                its=k.find(str1);
            }
            keywords[its->second].push_back(id);
            its=k.find(str2);                  //2
            if(its==k.end())
            {
                k.insert(S_Pair(str2,k.size()));
                its=k.find(str2);
            }
            keywords[its->second].push_back(id);
            its=k.find(str3);                  //3
            if(its==k.end())
            {
                k.insert(S_Pair(str3,k.size()));
                its=k.find(str3);
            }
            keywords[its->second].push_back(id);
            its=k.find(str4);                  //4
            if(its==k.end())
            {
                k.insert(S_Pair(str4,k.size()));
                its=k.find(str4);
            }
            keywords[its->second].push_back(id);
            its=k.find(str5);                  //5
            if(its==k.end())
            {
                k.insert(S_Pair(str5,k.size()));
                its=k.find(str5);
            }
            keywords[its->second].push_back(id);
        }
        gets(tmp);
        string a(tmp);
        if(p.empty())
            p.insert(S_Pair(a,p.size()));
        its=p.find(a);
        if(its==p.end())
        {
            p.insert(S_Pair(a,p.size()));
            its=p.find(a);
        }
        press[its->second].push_back(id);
        cin>>j;
        year[j].push_back(id);
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
            its=t.find(b);
            if(its==t.end())
            {
                cout<<"Not Found"<<endl;
                continue;
            }
            int aa=its->second;
            title[aa].sort();
            for(it=title[aa].begin();it!=title[aa].end();it++)
                printf("%07d\n",*it);
        }
        else if(j==2)
        {
            gets(tmp);
            string c(tmp);
            cout<<j<<":"<<" "<<c<<endl;
            its=w.find(c);
            if(its==w.end())
            {
                cout<<"Not Found"<<endl;
                continue;
            }
            int aa=its->second;
            writer[aa].sort();
            for(it=writer[aa].begin();it!=writer[aa].end();it++)
                printf("%07d\n",*it);
        }
        else if(j==3)
        {
            gets(tmp);
            string c(tmp);
            cout<<j<<":"<<" "<<c<<endl;
            its=k.find(c);
            if(its==k.end())
            {
                cout<<"Not Found"<<endl;
                continue;
            }
            int aa=its->second;
            keywords[aa].sort();
            for(it=keywords[aa].begin();it!=keywords[aa].end();it++)
                printf("%07d\n",*it);
        }
        else if(j==4)
        {
            gets(tmp);
            string c(tmp);
            cout<<j<<":"<<" "<<c<<endl;
            its=p.find(c);
            if(its==p.end())
            {
                cout<<"Not Found"<<endl;
                continue;
            }
            int aa=its->second;
            press[aa].sort();
            for(it=press[aa].begin();it!=press[aa].end();it++)
                printf("%07d\n",*it);
        }
        else
        {
            int y;
            cin>>y;
            cout<<j<<":"<<" ";
            printf("%04d\n",y);
            if(year[y].empty())
            {
                cout<<"Not Found"<<endl;
                continue;
            }
            year[y].sort();
            for(it=year[y].begin();it!=year[y].end();it++)
                printf("%07d\n",*it);
        }
    }
    return 0;
}
