#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5;
const int M=1e6+5;
const int K=15;
int n,m,k,cnt,ans,fa[N],cost[K],dis[K][N],pa[N],dep[N],fans,pv[N];
pair<int,int>pl;
struct node{
	int u,v,w;
}e[M];
struct edge{
	int to,val;
};
vector<edge>g[N];
bool cmp(node P,node Q){
	return P.w<Q.w;
}
int find(int x){
	return (x==fa[x])?x:fa[x]=find(fa[x]);
}
void kruskal(){
	for(int i=1;i<=m;i++){
		int fu=find(e[i].u),fv=find(e[i].v);
		if(fu==fv)continue;
		fa[fu]=fv;
		cnt++;
		ans+=e[i].w;
		g[e[i].u].push_back({e[i].v,e[i].w});
		g[e[i].v].push_back({e[i].u,e[i].w});
		if(cnt==n-1){
			break;
		}
	}
}
void dfss(int u,int la){
	for(auto v:g[u]){
		if(v.to==la)continue;
		pa[v.to]=u;
		pv[v.to]=v.val;
		dep[v.to]=dep[u]+1;
		dfss(v.to,u);
	}
}
void get(int as,int i,int j){
	if(dep[i]>dep[j]){
		swap(i,j);
	}
	if(dis[as][i]+dis[as][j]>=pv[j])return;
	for(auto h=g[pa[j]].begin();h!=g[pa[j]].end();h++){
		if((*h).to==j){
			g[pa[j]].erase(h);
			break;
		}
	}
	g[i].push_back({j,dis[as][i]+dis[as][j]});
}
void solve(vector<int>cho,vector<vector<int>>pre){
	int now_ans=ans;
	for(int as=1;as<=k;as++){
		if(cho[as]==1){
			now_ans+=cost[as];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				get(as,i,j);
			}
		}
	}
	
}
void dfs(int step,vector<int>cho,vector<vector<int>>pre){
	if(step==k+1){
		solve(cho,pre);
		return;
	}
	cho.push_back(0);
	dfs(step+1,cho,pre);
	cho.pop_back();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			pre[i][j]=min(pre[i][j],dis[step][i]+dis[step][j]);
		}
	}
	cho.push_back(1);
	dfs(step+1,cho,pre);
	cho.pop_back();
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+m+1,cmp);
	kruskal();
	if(k==0){
		cout<<ans;
		return 0;
	}
	dfss(1,0);
	for(int i=1;i<=k;i++){
		cin>>cost[i];
		for(int j=1;j<=n;j++){
			cin>>dis[i][j];
		}
	}
	vector<int>cho;
	cho.push_back(0);
	vector<vector<int>>pre(n+1,vector<int>(n+1));
	dfs(1,cho,pre);
	cout<<fans;
}