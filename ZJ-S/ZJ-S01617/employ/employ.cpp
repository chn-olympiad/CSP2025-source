#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=5e2+10;
constexpr int mod=998244353;
int c[maxn];
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    int n,m;
    scanf("%lld%lld",&n,&m);
    string s;
    cin>>s;
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&c[i]);
    }
    int f1=0;
    for(auto i:s)
    {
        if(i-'1'==0)
        {
            f1++;
        }
    }
    if(f1==n)
    {
        int x=1;
        int fq=0;
        for(int i=1;i<=n;++i)
        {
            if(c[i]-fq<=0)
            {
                fq++;
                continue;
            }
            x*=i;
            x%=mod;
        }
        printf("%lld\n",x);
    }

    return 0;
}
