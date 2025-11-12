#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1000000+5;
int n,m,k;
bool vis[maxn];
struct edge{int to,w;};
vector<edge> vt[maxn];
int dfs(int u){
	if(vis[u]) return 0;
	int ans=0; vis[u]=1;
	for(auto v:vt[u]){
		int to=v.to;
		if(vis[to]) continue;
		ans+=v.w; ans+=dfs(to);
	}return ans;
}
bool cmp(edge e1,edge e2){return e1.w<e2.w;}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w; cin>>u>>v>>w;
		vt[u].push_back({v,w}); vt[v].push_back({u,w});
	} // 建树
	for(int i=1;i<=n;i++)
	sort(vt[i].begin(),vt[i].end(),cmp);
	int ans=0x7f7f7f7f;
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		int num=dfs(i);
		if(num<ans) ans=num;
	} 
	cout<<ans<<endl;
	return 0;
}