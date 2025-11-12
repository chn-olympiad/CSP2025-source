#include<iostream>
#include<vector>
#define int long long
using namespace std;
int n,m,k,a[10015],val[10015][10015],t[10015],ans=1e18;
bool mt[10015];
vector<int> vec[10015];
void dfs(int x,int c,int mon){
	if(c==n){
		ans=min(ans,mon);
		return;
	}
	for(int i=0;i<vec[x].size();i++){
		if(mt[vec[x][i]]) continue;
		mt[vec[x][i]]=1;
		dfs(vec[x][i],c+1,mon+t[vec[x][i]]+val[x][vec[x][i]]);
		mt[vec[x][i]]=0;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	int u,v,vas;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&vas);
		val[u][v]=vas;
		val[v][u]=vas;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&t[n+i]);
		for(int j=1;j<=n;j++){
			vec[n+i].push_back(j);
			vec[j].push_back(n+i);
			scanf("%lld",val[i+n][j]);
			val[j][i+n]=val[i+n][j];
		}
	}
	for(int i=1;i<=n+k;i++){
		mt[i]=1;
		dfs(i,0,t[i]);
		mt[i]=0;
	}
	printf("%lld",ans);
	return 0;
}
