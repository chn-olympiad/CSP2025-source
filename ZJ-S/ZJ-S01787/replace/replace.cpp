#include<bits/stdc++.h>
using namespace std;
const long long P=2333;
int n,q;
char s1[5000005],s2[5000005];

int cnt;
map<pair<unsigned long long,unsigned long long>,int> mp;
vector<pair<unsigned long long,unsigned long long> > vec[200005];


unordered_set<unsigned long long> st1,st2;
int main ()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("\n%s %s",s1+1,s2+1);
        int len=strlen(s1+1);
        bool flag=true;
        for(int j=1;j<=len;j++)
        {
            if(s1[j]!=s2[j])
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            continue;
        }
        int l=0,r=len+1;
        while(s1[l+1]==s2[l+1])
        {
            l++;
        }
        while(s1[r-1]==s2[r-1])
        {
            r--;
        }
        unsigned long long h1=0,h2=0;
        for(int j=l+1;j<=r-1;j++)
        {
            h1=h1*P+s1[j]-'0';
            h2=h2*P+s2[j]-'0';
        }
        if(!mp.count({h1,h2}))
        {
            mp[{h1,h2}]=++cnt;
        }
        int id=mp[{h1,h2}];
        h1=0;h2=0;
        for(int j=l;j>=1;j--)
        {
            h1=h1*P+s1[j]-'0';
        }
        for(int j=r;j<=len;j++)
        {
            h2=h2*P+s1[j]-'0';
        }
        vec[id].emplace_back(h1,h2);
    }
    while(q--)
    {
        scanf("\n%s %s",s1+1,s2+1);
        if(strlen(s1+1)!=strlen(s2+1))
        {
            printf("0\n");
            continue;
        }
        int len=strlen(s1+1);
        int l=0,r=len+1;
        while(s1[l+1]==s2[l+1])
        {
            l++;
        }
        while(s1[r-1]==s2[r-1])
        {
            r--;
        }
        unsigned long long h1=0,h2=0;
        for(int j=l+1;j<=r-1;j++)
        {
            h1=h1*P+s1[j]-'0';
            h2=h2*P+s2[j]-'0';
        }
        if(!mp.count({h1,h2}))
        {
            printf("0\n");
            continue;
        }
        int id=mp[{h1,h2}];
        h1=0;h2=0;
        st1.clear();st2.clear();
        st1.insert(0);st2.insert(0);
        for(int j=l;j>=1;j--)
        {
            h1=h1*P+s1[j]-'0';
            st1.insert(h1);
        }
        for(int j=r;j<=len;j++)
        {
            h2=h2*P+s1[j]-'0';
            st2.insert(h2);
        }
        int ans=0;
        for(pair<unsigned long long,unsigned long long> x:vec[id])
        {
            if((st1.count(x.first))&&(st2.count(x.second)))
            {
                ans++;
            }
        }
        printf("%d\n",ans);
    }
}