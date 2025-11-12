#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
int n,m,k;
int a[15],p[10010],sz[10010];
struct Edge{
    int a,b,c;
}ed[1100010];
inline int find(int x)
{
    if(p[x]!=x)p[x]=find(p[x]);
    return p[x];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    int i,j;cin>>n>>m>>k;
    for(i=1;i<=n;i++)p[i]=i,sz[i]=1;
    for(i=1;i<=m;i++)cin>>ed[i].a>>ed[i].b>>ed[i].c;
    sort(ed+1,ed+m+1,[&](const Edge &x,const Edge &y){
        return x.c<y.c;
    });int c=0;
    for(i=1;i<=m;i++){
		int x=find(ed[i].a),y=find(ed[i].b);
		if(x==y)continue;
		if(sz[x]<sz[y])x^=y^=x^=y;
		p[y]=x,sz[x]+=sz[y];
		ed[++c]=ed[i];
	}m=c;
    for(i=1;i<=k;i++){
        cin>>a[i];
        for(j=1;j<=n;j++){
            int x;cin>>x;
            ed[++m]={n+i,j,x};
        }
    }sort(ed+1,ed+m+1,[&](const Edge &x,const Edge &y){
        return x.c<y.c;
    });LL ans=1e18;
    for(j=0;j<(1<<k);j++){
        LL s=0;
        for(i=0;i<k;i++)
            if(j>>i&1)s+=a[i+1];

        for(i=1;i<=n+k;i++)p[i]=i,sz[i]=1;
        for(i=1;i<=m;i++){
            if(ed[i].a>n&&!(j>>(ed[i].a-n-1)&1))continue;
            int x=find(ed[i].a),y=find(ed[i].b);
            if(x==y)continue;
            s+=ed[i].c;
            if(sz[x]<sz[y])x^=y^=x^=y;
            p[y]=x,sz[x]+=sz[y];
        }ans=min(ans,s);
    }cout<<ans;
}
