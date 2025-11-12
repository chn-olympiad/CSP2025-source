#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int dis[10010];
bool flag[10010];
vector<pair<int,int>> edge[10010];
priority_queue<pair<int,int>> q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,lng;
		cin>>u>>v>>lng;
		edge[u].push_back(make_pair(v,lng));
		edge[v].push_back(make_pair(u,lng));
	}
	for(int i=1;i<=n;i++){
		dis[i]=2e9;
	}
	dis[1]=0;
	q.push(make_pair(0,1));
	for(int i=1;i<=n;i++){
		while(flag[q.top().second]==1){
			q.pop();
		}
		int t1=-1*q.top().first,t2=q.top().second;
		q.pop();
		flag[t2]=1;
		ans+=t1;
		for(int j=0;j<edge[t2].size();j++){
			if(flag[edge[t2][j].second]==0&&dis[edge[t2][j].second]>dis[t2]+edge[t2][j].first){
				dis[edge[t2][j].second]=dis[t2]+edge[t2][j].first;
				q.push(make_pair(-1*edge[t2][j].first,edge[t2][j].second));
			}
		}
	}
	cout<<ans;
	return 0;
}
