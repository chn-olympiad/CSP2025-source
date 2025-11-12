#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int maxn=2e4+5;
vector<pair<int,int>>g[maxn];
int vis[maxn],a[maxn],t[maxn],vis1[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(t,0x3f,sizeof t);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	while(k--){
		int x;
		cin>>x;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				g[i].push_back({j,a[i]+a[j]+x});
				g[j].push_back({i,a[i]+a[j]+x});
			}
		}
	}
	long long ans=0;
	vis[1]=1;
	queue<int>q;
	q.push(1);
	priority_queue<pair<int,int>>q1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
	//	cout<<u; 
		int o=0;
		for(auto it:g[u]){
	//		cout<<it.first<<" ";
			if(vis[it.first]==0){
				if(it.second<t[it.first]){
					q1.push({-it.second,it.first});
				} 
				t[it.first]=min(t[it.first],it.second);
			}
		}
		while(1&&!q1.empty()){
			auto  op=q1.top();
			q1.pop();
		//	cout<<op.second<<" ";
			if(vis[op.second]==0){
				ans-=op.first;
				vis[op.second]=1;
				q.push(op.second);
				break;
			}
		}
	//	cout<<ans<<endl;
		
	}
	cout<<ans;

	return 0;
}

