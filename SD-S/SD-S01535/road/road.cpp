//40pts
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PI pair<int,int>
#define ls rt*2;
#define rs rt*2+1;
const int N=1e3+10;
const int K=1e4+10;
const int M=4e6+10;
const int INF=1e14;
int n,m,k;
int A;
int dis[N][N];
int ans;
int tot;
int u,v,w;
int c[20],a[20][K];
struct Edge{
	int u,v,w;
}e[M],g[M];
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
int f[K];
void init(){
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	return;
}
int find(int x){
	if(x==f[x]){
		return x;
	}
	return f[x]=find(f[x]);
}
int vis[20];
void Clear(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=INF;
		}
	}
	for(int i=1;i<=m;i++){
		dis[e[i].u][e[i].v]=min(dis[e[i].u][e[i].v],e[i].w);
		dis[e[i].v][e[i].u]=min(dis[e[i].v][e[i].u],e[i].w);
	}
	return;
}
int solve(){
	int res=0;
	init();
	Clear();
	for(int i=1;i<=k;i++){
		if(vis[i]){
			res+=c[i];
			for(int j=1;j<=n;j++){
				for(int l=j+1;l<=n;l++){
					int u=j,v=l;
					if(a[i][u]+a[i][v]<dis[u][v]){
						dis[u][v]=a[i][u]+a[i][v];
						dis[v][u]=a[i][u]+a[i][v];
					}
				}
			}
		}
	}
	tot=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			tot++;
			g[tot].u=i;
			g[tot].v=j;
			g[tot].w=dis[i][j];
		}
	}
	sort(g+1,g+tot+1,cmp);
	for(int i=1;i<=tot;i++){
		int u=g[i].u,v=g[i].v,w=g[i].w;
		if(find(u)!=find(v)){
			res+=w;
			f[find(u)]=find(v);
		}
	}
	return res;
}
void dfs(int x){
	if(x>k){
		ans=min(ans,solve());
		return;
	}
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
	dfs(x+1);
	return;
} 
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0){
			A=1;
		}
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0){
		init();
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=m;i++){
			int u=e[i].u,v=e[i].v,w=e[i].w;
			if(find(u)!=find(v)){
				ans+=w;
				f[find(u)]=find(v);
			}
		}
		cout<<ans;
		return 0;
	}
	if(!A&&n<=1000){
		init();
		Clear();
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				for(int l=j+1;l<=n;l++){
					int u=j,v=l;
					if(a[i][u]+a[i][v]<dis[u][v]){
						dis[u][v]=a[i][u]+a[i][v];
						dis[v][u]=a[i][u]+a[i][v];
					}
				}
			}
		}
		tot=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				tot++;
				e[tot].u=i;
				e[tot].v=j;
				e[tot].w=dis[i][j];
			}
		}
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=m;i++){
			int u=e[i].u,v=e[i].v,w=e[i].w;
			if(find(u)!=find(v)){
				ans+=w;
				f[find(u)]=find(v);
			}
		}
		cout<<ans;
		return 0;
	}
	if(n<=1000){
		ans=INF;
		dfs(1);
		cout<<ans;
		return 0;
	}
	return 0;
} 
/*
	
*/
