#include<bits/stdc++.h>
using namespace std;
#define int long long 
constexpr int maxn=2e6+10;
int cnt[maxn];
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    scanf("%lld%lld",&n,&k);
    vector<int>a(n+1),pre(n+1);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
        pre[i]=pre[i-1]^a[i];
    }
    if(n<=1000)
    {
        int las=0;
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            int is=0,c=las;
            for(;las<i;++las)
            {
                if((pre[i]^pre[las])==k)
                {
                    ++ans;
                    las=i;
                    is=1;
                    break;
                }
            }   
            if(!is)
            {
                las=c;
            }
        }
        printf("%lld\n",ans);
        return 0;
    }
    else
    {
        unordered_set<int>usex;
        int ans=0;
        usex.insert(0);
        for(int i=1;i<=n;++i)
        {
            int need=pre[i]^k;
            if(usex.count(need))
            {
                ++ans;
                usex.clear();
                usex.insert(pre[i]);
            }
            else
            {
                usex.insert(pre[i]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}