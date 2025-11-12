#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace awa
{
    const int N=500;
    const ll mod=998244353;
    int n,m,c[N+5],p[N+5];char s[N+5];

    ll ans;
    inline void qwq()
    {
        cin>>n>>m>>(s+1);
        for(int i=1;i<=n;++i) cin>>c[i];
        for(int i=1;i<=n;++i) p[i]=i;
        do
        {
            int cnt=0;
            for(int i=1;i<=n;++i)
                if((s[i]^48)&&(i-1-cnt<c[p[i]])) ++cnt;
            if(cnt>=m) ++ans;
        }while(next_permutation(p+1,p+n+1));
        cout<<ans<<'\n';
    }
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    return awa::qwq(),0;
}