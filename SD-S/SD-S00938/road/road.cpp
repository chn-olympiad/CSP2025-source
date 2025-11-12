#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define PII pair<int,int>
using namespace std;
int n,m,k;
vector<PII> w[10010];
int g[20][10010];
int gc[20];
priority_queue<PII,vector<PII>,greater<PII> > q;
bool vis[10010];
int kru(int stu){
	int ans=0;
	q.push({0,stu});
	while(q.size()){
		PII tp=q.top();q.pop();
		if(vis[tp.second]) continue;
		vis[tp.second]=1;
		ans+=tp.first;
		for(PII i:w[tp.second]){
			int v=i.first;
			int wl=i.second;
			q.push({wl,v});
		}
	}
	return ans;
}
int gans=0;
int dfs(int step){
	if(step==k+1){
		for(int i=1;i<=n;i++) vis[i]=0;
		int ret=kru(1);
//		cout<<ret<<"\n";
		return ret;
	}
	int ret=dfs(step+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			w[i].push_back({j,g[step][i]+g[step][j]});
			w[j].push_back({i,g[step][i]+g[step][j]});
		}
//		w[step].push_back({i,g[step][i]});
	}
	ret=min(ret,gc[step]+dfs(step+1));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			w[i].pop_back();
			w[j].pop_back();
		}
//		w[step].push_back({i,g[step][i]});
	}
	return ret;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,z;
		scanf("%d%d%d",&u,&v,&z);
		w[u].push_back({v,z});
		w[v].push_back({u,z});
	}
	for(int i=1;i<=k;i++){
		int c;
		scanf("%d",&c);
		gc[i]=c;
		for(int j=1;j<=n;j++){
			int a;
			scanf("%d",&a);
			g[i][j]=a;
		}
	}
	cout<<dfs(1);
	return 0;
}
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4
