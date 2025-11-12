#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> PII;
vector<PII> vt[100010];
int vis[100010];
int bf[100],bv[100100];
int f[100];
priority_queue<PII,vector<PII> ,greater<PII> > pq; 
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		vt[u].push_back({v,w});
		vt[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>bf[i];
		for(int j=1;j<=n;j++){
			cin>>bv[i];
		}
	}
	int tg=n-1;
	for(auto i:vt[1]){
		pq.push({i.second,i.first});
	}
	vis[1]=1;
	int ans=0;
	while(tg){
		int sumd=pq.top().first;
		int id=pq.top().second;
		pq.pop();
		
		if(vis[id]) continue;
		vis[id]=1;
		ans+=sumd;
		tg--;
		for(auto i:vt[id]){
			if(vis[i.first]) continue;
			pq.push({i.second,i.first});	
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*



*/
