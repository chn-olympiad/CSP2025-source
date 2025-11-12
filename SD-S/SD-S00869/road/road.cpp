#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
const int mod=998244353;
int a[N],n,m,k,vis[N],c[20][N],ans,s;
struct node{
	int v,w;
	friend bool operator <(node a,node b){
		return a.w>b.w;
	}
};
vector<node>V[N];
priority_queue<node>q;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		V[u].push_back({v,w});
		V[v].push_back({u,w});
	}queue<int>Q;
	Q.push(1);
	while(!Q.empty()){
		int u=Q.front();Q.pop();s++;
		vis[u]=1;
		for(int i=0;i<V[u].size();i++){
			if(vis[V[u][i].v]==0){
				q.push({V[u][i].v,V[u][i].w});
			}
		}
		while(!q.empty()&&vis[q.top().v]==1)  q.pop();
		if(q.empty()||s>=n)  break;
		int v=q.top().v,w=q.top().w;
		Q.push(v);
		ans+=w;
	}
	for(int i=1;i<=k;i++)  for(int j=0;j<=n;j++)  cin>>c[i][j];
	cout<<ans;
	return 0;
}
