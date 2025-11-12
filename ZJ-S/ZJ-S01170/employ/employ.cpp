#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=1e4+20,mod=998244353,maxm=2e6+10,maxk=15;
int ans=0;
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    scanf("%lld%lld",&n,&m);
    string s;
    cin>>s;
    vector<int>c(n+1),xu(n+1);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&c[i]);
        xu[i]=i;
    }
    if(n<=10)
    {
        
        do
        {
            int is=1;
            int ren=0;
            int shi=0;
            for(int i=1;i<=n;++i)
            {
                if(s[i-1]=='0'||c[xu[i]]<=shi)
                {
                    ++shi;
                }
                else
                {
                    ++ren;
                    if(ren>=m)
                    {
                        ++ans;
                        ans%=mod;
                        break;
                    }
                }
            }
        }while(next_permutation(xu.begin()+1,xu.end()));
        printf("%lld\n",ans);
    }
    return 0;
}
