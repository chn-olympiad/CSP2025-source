#include<bits/stdc++.h>
using namespace std;
const int N=1e4+3;
#define ll long long
int n,m,k,edge[11][N],vis[N],ans,minn[12];
vector<pair<int,int>>e[N];
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
int len(int u,int v){
	for(auto i:e[u]){
		if(i.second==v)return i.first;
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	fill(minn+1,minn+1+11,0x7fffffff);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({w,v}),e[v].push_back({w,u});
	}
	for(int i=1;i<=k;i++){
		cin>>edge[i][0];
		for(int j=1;j<=n;j++)cin>>edge[i][j];
	}
	for(auto i:e[1])q.push({i.first,{i.second,1}});//weight to now
	for(int i=1;i<n;i++){
		auto t=q.top();q.pop();
		int leth=len(t.second.first,t.second.second),pos=0;
		for(int j=1;j<=k;j++){
			minn[j]=min(minn[j],edge[j][t.second.second]);
			if(edge[j][0]+minn[j]+edge[j][t.second.first]<=leth){
				pos=j;leth=edge[j][0]+minn[j]+edge[j][t.second.first];
			}
		}
		if(pos){
			ans+=edge[pos][0]+minn[pos]+edge[pos][t.second.first];
			for(int j=1;j<=n;j++){
				if(vis[j]==1)continue;
				q.push({edge[pos][j],{j,1}});
			}
		}
		else ans+=t.first;
		for(auto j:e[t.second.first]){
			if(j.second==t.second.second||vis[j.second]==1)continue;
			vis[t.second.first]=1;
			q.push({j.first,{j.second,t.second.first}});
		}
	}
	cout<<ans;
	return 0;
}