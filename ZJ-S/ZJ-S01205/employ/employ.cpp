#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int mod=998244353;
constexpr int maxn=5e3+10;
int n,m;
char s[maxn];
int c[maxn];
int ky[maxn];
int pass;
int ac[maxn];
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    scanf("%s",s+1);
    for(int i=1;i<=n;++i)
    {
        if(s[i]=='0')
        {
           ++pass;
        }
        else
        {
            ac[++ac[0]]=pass;
        }
    }
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",c+i);
    }
    sort(c+1,c+1+n);
    for(int i=ac[0];i>=1;--i)
    {
        for(int j=n;j>=1;--j)
        {
           // printf("%lld %lld\n",i,j);
            if(c[j]>ac[i])
            {
                ++ky[i];
            }
            else
            {
                break;
            }
        }
    }
//    for(int i=1;i<=m;++i)
//    {
//        printf("%lld ",ky[i]);
//    }
    int ans=1;
    for(int i=ac[0];i>=1;--i)
    {
        ans*=ky[i];
    }
    for(int i=ac[0];i>=2;--i)
    {
        ans-=((ky[i])*(i-1));
    }
    printf("%lld\n",ans%mod);
    return 0;
}
