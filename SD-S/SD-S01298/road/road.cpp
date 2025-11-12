#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3f;
const int N=1e6+10;
int n,m,k;
ll g[10015][10015],dis[10015],vis[10015],c[15];
ll a[15][10005],d[10005][10005];
struct node{
	int a,b;
	ll w;
}e[N];
int fa[N];
void init(){
	for (int i=1; i<=n; i++){
		fa[i]=i;
	}
}
int fnd(int x){
	if (fa[x]==x) return x;
	return fa[x]=fnd(fa[x]);
}
ll prim(){
	ll res=0;
	for (int i=1; i<=n; i++) dis[i]=inf;
	for (int i=0; i<n; i++){
		int t=-1;
		for (int j=1; j<=n; j++){
			if (!vis[j]&&(t==-1||dis[t]>dis[j])){
				t=j;
			}
		}
		vis[t]=1;
		if (i&&dis[t]>=inf/2) return -inf;
		if (i) res+=dis[t];
		for (int j=1; j<=n; j++){
			dis[j]=min(dis[j],g[t][j]);
		}
	}
	return res;
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	memset(g,0x3f,sizeof(g));
	for (int i=1; i<=n+k; i++){
		g[i][i]=0;
	}
	for (int i=1; i<=m; i++){
		int u,v;
		ll w;
		cin>>u>>v>>w;
		e[i].a=u,e[i].b=v,e[i].w=w;
		g[u][v]=min(g[u][v],w);
		g[v][u]=min(g[v][u],w);
	}
	if (k==0){
		cout<<prim();
		return 0;
	}
	int flag=0,flag2=0;
	for (int i=1; i<=k; i++){
		cin>>c[i];
		flag2=0;
		if (c[i]!=0) flag2=1;
		for (int j=1; j<=n; j++){
			cin>>a[i+n][j];
			if (a[i+n][j]!=0) flag2=1;
		}
		if (!flag2) flag=1;
	}
	if (flag){
		cout<<0;
		return 0;
	}
	init();
	sort(e+1,e+m+1,cmp);
	ll res=0,maxx=-1;
	for (int i=1; i<=m; i++){
		int u=fnd(e[i].a),v=fnd(e[i].b);
		if (u!=v){
			fa[v]=u;
			res+=e[i].w;
			d[e[i].a][e[i].b]=d[e[i].b][e[i].a]=e[i].w;
	//		cout<<d[e[i].a][e[i].b]<<" "<<e[i].a<<" "<<e[i].b<<'\n';
	//		maxx=max(maxx,e[i].w);
		}
	}
	for (int i=1; i<=k; i++){
		for (int j=1; j<=n; j++){
			for (int l=j+1; l<=n; l++){
				if (j==l) continue;
			//	cout<<c[i]+a[i+n][j]+a[i+n][l]<<" "<<d[j][l]<<'\n';
				if (c[i]+a[i+n][j]+a[i+n][l]<d[j][l]){
					res-=d[j][l];
					res+=c[i]+a[i+n][j]+a[i+n][l];
					
					d[j][l]=d[l][j]=c[i]+a[i+n][j]+a[i+n][l];
				}
			} 
		}
	}
	cout<<res;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
