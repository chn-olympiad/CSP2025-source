#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int maxn=1e6+5,maxk=15;
int n,m,k,u,v,w;
struct edge{
	int v,w;
};
vector<edge>G[maxn];
int c[maxk],a[maxk][maxn];
ll dfn[maxn],low[maxn],st,tim,fa[maxn][22],dep[maxn];
void dfs(int u,int fa1){
	fa[u][0]=fa1;
	dep[u]=dep[fa1]+1;
	for(edge t:G[u]){
		v=t.v;
		if(v==fa1)continue;
		dfs(v,u);
	}
	return ;
}
int lca(int x,int y){
	if(dep[x]>dep[y])swap(x,y);
	for(int i=20;i>=0;i--){
		if(fa[y][0]<fa[x][0]){
			x=fa[x][0];
		}
	}
	if(x==y)return x;
	for(int i=20;i>=0;i++){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][0],y=fa[y][0];
		}
	}
	return fa[x][0];
}
int Tarjan(int x){
	dfn[x]=++tim;
	for(edge t:G[u]){
		int v=t.v;
		cout<<v<<" ";
	}
	return 0;
}
bool flaga=1;
ll tot=0;
void solov();
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		tot+=w;
	}
	for(int j=1;j<=k;j++){
		cin>>c[j];
		if(c[j]!=0)flaga=0;
		for(int i=1;i<=n;i++){
			cin>>a[j][i];
		}
	}
	if(flaga==1){
		solov();
	}
	return 0;
}
void solov(){
	cout<<w<<endl;
}
