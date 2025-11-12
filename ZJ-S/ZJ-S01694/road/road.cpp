#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define F first
#define S second
#define INF 0x3f3f3f3f
using namespace std;
int n,m,k,c[15],dis[10050],ans=INT_MAX;
bool vis[15],has[10050];
vector<pii>vec[10050];
bool cmp(pii a,pii b){
	return a.S<b.S;
}
int solve(){
	memset(has,0,sizeof has);
	int res=0;
	for(int i=1;i<=k;i++)
		if(vis[i])res+=c[i];
	queue<int> que;
	que.push(1);
	has[1]=true;
	while(que.size()){
		int u=que.front();
		que.pop();
		for(int i=0;i<vec[u].size();i++){
			if(!has[vec[u][i].F]&&vec[u][i].F<=n){
				has[vec[u][i].F]=true;
				res+=vec[u][i].S;
				que.push(vec[u][i].F);
				if(res>ans)return ans;
			}
		}
	}
	return res;
}
void dfs(int dep,int sum){
	if(sum>=ans)return;
	if(dep==k+1){
		ans=min(ans,solve());
		return;
	}
	vis[dep]=true;
	dfs(dep+1,sum+c[dep]);
	vis[dep]=false;
	dfs(dep+1,sum);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		vec[u].push_back({v,w});
		vec[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			vec[i+n].push_back({j,w});
			vec[j].push_back({i+n,w});
		}
	}
	for(int i=1;i<=n+k;i++){
		sort(vec[i].begin(),vec[i].end(),cmp);
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}
