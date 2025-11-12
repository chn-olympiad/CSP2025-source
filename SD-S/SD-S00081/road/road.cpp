#include<bits/stdc++.h>
using namespace std;
const int M=1e6+9;
const int N=1e4+9;
int n,m,k;
int w[N],v[N],u[N];
int c[12],a[12][N];
int du[N];
struct edge{
	int to,v;
};
vector<edge>g[N];
long long ans;
void dfs(int x){
	for(int i=0;i<g[x].size();i++){
		int to=g[x][i].to;
		int v=g[x][i].v;
		if(du[x]>1&&du[to]>1){
			du[x]--;
			du[to]--;
			ans-=v;
			dfs(to);
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
    	cin>>u[i]>>v[i]>>w[i];
    	g[u[i]].push_back(edge{v[i],w[i]});
    	ans+=w[i];
    	du[u[i]]++;
    	du[v[i]]++;
	}
	dfs(1);
	cout<<ans;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	
	return 0;
}
