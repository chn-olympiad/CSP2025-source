#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define Inf 0x3f3f3f3f3f3f3f3fll

const int N=1e4+20;
const int M=2e6+10;

int fa[N],siz[N],cnt,n,m,k,tot;
ll a[32][N],c[32];
struct P{int u,v;ll w;}tb[M],b[M];

bool cmp(P x,P y){return x.w<y.w;}

int find(int x)
{
    if(x!=fa[x]) fa[x]=find(fa[x]);
    return fa[x];
}

inline void merge(int x,int y)
{
    x=find(x),y=find(y);
    if(x==y) return;
    if(siz[x]<siz[y]) swap(x,y);
    fa[y]=x;
    siz[x]+=siz[y];
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++) cin >> tb[i].u >> tb[i].v >> tb[i].w;
    for(int i=1;i<=k;i++)
    {
        cin >> c[i];
        for(int j=1;j<=n;j++) cin >> a[i][j];
    }           
    sort(tb+1,tb+m+1,cmp);    
    for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
    for(int i=1;i<=m;i++)
    {
        if(find(tb[i].u)!=find(tb[i].v))
        {
            b[++cnt]=tb[i];
            merge(tb[i].u,tb[i].v);
        }
    }
    m=cnt;
    ll ans=Inf;
    for(int s=0;s<(1<<k);s++)
    {
        ll sum=0;
        int cnt=1;
        tot=m;
        for(int i=1;i<=k;i++)
        {
            if((s>>(i-1))&1)
            {
                cnt--;
                sum+=c[i];
                for(int j=1;j<=n;j++) b[++tot]={n+i,j,a[i][j]};
            }
        }
        if(m<tot) sort(b+m+1,b+tot+1,cmp);
        for(int i=1;i<=n+k;i++) fa[i]=i,siz[i]=1;
        int pos1=1,pos2=m+1;
        for(int i=1;i<=tot;i++)
        {
            int id;
            if(pos1>m) id=pos2++;
         	else if(pos2>tot) id=pos1++;
            else if(b[pos1].w<b[pos2].w) id=pos1++;
            else id=pos2++;
            if(find(b[id].u)!=find(b[id].v))
            {
                sum+=b[id].w;
                merge(b[id].u,b[id].v);
                cnt++;
                if(cnt==n) break;
            }
        }
        ans=min(ans,sum);  
    }
    cout << ans << '\n';
    return 0;
}

                                              