#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int maxn=1e6+5;
int n,m,k,c[maxn],a[15][maxn],fa[maxn],u,v,cnt,sum;
long long ans,tmp;
bool vis[maxn];
struct edge{int x,y,z;}e[maxn],g[maxn];
bool cmp(edge u,edge v){return u.z<v.z;}
int gf(int x){return (fa[x]==x ? x : fa[x]=gf(fa[x]));}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k ;
	for(int i=1;i<=m;i++) cin >> e[i].x >> e[i].y >> e[i].z ;
	for(int i=1;i<=k;i++){
		cin >> c[i] ;
		for(int j=1;j<=n;j++) cin >> a[i][j] ;
	}for(int i=1;i<=n;i++) fa[i]=i;
	sort(e+1,e+m+1,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
//		cout << e[i].z << "\n" ;
		u=gf(e[i].x),v=gf(e[i].y);
		if(u==v) continue;
		ans+=e[i].z;
		fa[u]=v,cnt++,vis[i]=1;
		if(cnt==n-1) break;
	}cnt=0;
	for(int i=1;i<=m;i++) if(vis[i]) e[++cnt]=e[i];
//	for(int i=1;i<=cnt;i++) cout << e[i].x << " " << e[i].y << " " << e[i].z << "\n" ;
	for(int s=1;s<(1 << k);s++){
		tmp=0,cnt=n-1,sum=n-1;
		for(int i=1;i<n;i++) g[i]=e[i];
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=k;i++){
			if((s >> (i-1)) & 1){
				fa[n+i]=n+i,++sum,tmp+=c[i];
				for(int j=1;j<=n;j++) g[++cnt]={n+i,j,a[i][j]};
			}
		}sort(g+1,g+cnt+1,cmp);
//		cout << sum << "\n" ;
		for(int i=1;i<=cnt;i++){
			u=gf(g[i].x),v=gf(g[i].y);
			if(u==v) continue;
//			cout << "k" << e[i].x << " " << e[i].y << " " << e[]<< "\n" ;
			tmp+=g[i].z;
			fa[u]=v,--sum;
			if(!sum) break;
		}ans=min(ans,tmp);
//		cout << tmp << "\n" ;
	}cout << ans ;
	return 0;
}
