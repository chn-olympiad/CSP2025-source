#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace awa
{
    const int N=1e4,M=1e6,K=10;

    int n,m,k;

    struct edge{int u,v;ll w;}e[M+5];
    inline bool operator<(const edge& x,const edge& y){return x.w<y.w;}
    edge q[M+N*K+5];int len;

    ll c[K+5],s[K+5][N+5];int id[K+5],fa[N+5];
    int find(const int x){return (fa[x]^x)?fa[x]=find(fa[x]):x;}

    ll ans=0x3f3f3f3f3f3f3f3f;
    bool flag=false;
    inline void qwq()
    {
        cin>>n>>m>>k;
        for(int i=1;i<=m;++i)
            cin>>q[i].u>>q[i].v>>q[i].w;
        len=m,m=0;
        sort(q+1,q+len+1);
        for(int i=1;i<=n;++i) fa[i]=i;
        for(int i=1;i<=len;++i)
            if(find(q[i].u)^find(q[i].v))
                fa[find(q[i].u)]=find(q[i].v),e[++m]=q[i];
        for(int i=1;i<=k;++i)
        {
            cin>>c[i],id[i]=1;
            for(int j=1;j<=n;++j)
            {
                cin>>s[i][j];
                if(s[i][id[i]]>s[i][j]) id[i]=j;
            }if(c[i]+s[i][id[i]]) flag=true;
        }
        for(int o=flag?0:(1<<k)-1;o<(1<<k);++o)
        {
            ll res=len=0;
            for(int i=1;i<=k;++i)
                if(o&(1<<(i-1)))
                {
                    res+=c[i]+s[i][id[i]];
                    for(int j=1;j<=n;++j)
                        if(j^id[i]) q[++len]={id[i],j,s[i][j]};
                }
            for(int i=1;i<=m;++i) q[++len]=e[i];
            sort(q+1,q+len+1);
            for(int i=1;i<=n;++i) fa[i]=i;
            for(int i=1;i<=len;++i)
                if(find(q[i].u)^find(q[i].v))
                    fa[find(q[i].u)]=find(q[i].v),res+=q[i].w;
            ans=min(ans,res);
        }cout<<ans<<'\n';
    }
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    return awa::qwq(),0;
}