#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int n,q;
const long long MOD=1e9+7;
long long hashs1[200005];
long long hashs2[200005];
long long hasht1[2000005];
long long hasht2[2000005];
long long p[2000005];
int sz[200005];
int id(char c)
{
    return c-'a'+1;
}
long long Hash(int l,int r,int x)
{
    if(x==1)
    {
        return ((hasht1[r]-hasht1[l-1]*p[r-l+1])%MOD+MOD)%MOD;
    }
    if(x==2)
    {
        return ((hasht2[r]-hasht2[l-1]*p[r-l+1])%MOD+MOD)%MOD;
    }
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    p[0]=1;
    for(int i=1;i<=2e6;i++)
    {
        p[i]=p[i-1]*27%MOD;
    }
    for(int i=1;i<=n;i++)
    {
        string s1,s2;
        cin>>s1>>s2;
        sz[i]=s1.size();
        for(int j=0;j<s1.size();j++)
        {
            hashs1[i]=(hashs1[i]*27+id(s1[j]))%MOD;
            hashs2[i]=(hashs2[i]*27+id(s2[j]))%MOD;
        }
    }
    while(q--)
    {
        string t1,t2;
        cin>>t1>>t2;
        memset(hasht1,0,sizeof(hasht1));
        memset(hasht2,0,sizeof(hasht2));
        for(int i=0;i<t1.size();i++)
        {
            hasht1[i+1]=(hasht1[i]*27+id(t1[i]))%MOD;
            hasht2[i+1]=(hasht2[i]*27+id(t2[i]))%MOD;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int len=sz[i];
            for(int l=1;l+len-1<=t1.size();l++)
            {
                int r=l+len-1;
                if(Hash(l,r,1)==hashs1[i]&&Hash(l,r,2)==hashs2[i]&&Hash(1,l-1,1)==Hash(1,l-1,2)&&Hash(r+1,t1.size(),1)==Hash(r+1,t2.size(),2))
                {
                    //cout<<l<<" "<<r<<endl;
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
