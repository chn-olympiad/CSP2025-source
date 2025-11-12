#include<bits/stdc++.h>
using namespace std;
constexpr int MAXN=2e5+10,base1=131,mod1=998244353;
string s1[MAXN],s2[MAXN];
long long hash_1_1[MAXN],hash_1_2[MAXN];
long long my_hash(const string&c)
{
    long long ans=0;
    for(int i=0;i<c.size();i++)
    {
        ans*=base1;
        ans+=c[i];
        ans%=mod1;
    }
    return ans;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++)
    {
        cin>>s1[i]>>s2[i];
        hash_1_1[i]=my_hash(s1[i]);
        hash_1_2[i]=my_hash(s2[i]);
    }
    for(int i=0;i<q;i++)
    {
        string q1,q2;
        cin>>q1>>q2;
        vector<long long>hash_q1,hash_q2;
        if(q1.size()!=q2.size())
        {
            puts("0");
            continue;
        }
        int ans=0;
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<=int(q1.size())-int(s1[j].size());k++)
            {
                if(q1.substr(k,s1[j].size())==s1[j]&&q2.substr(k,s2[j].size())==s2[j])
                {
                    auto d=q1.substr(0,k)+s2[j]+q1.substr(k+s1[j].size(),q1.size()-k+s1[j].size());
                    ans+=d==q2;
                }
            }
        }
        printf("%d\n",ans);
    }
}