#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
priority_queue<pii,vector<pii>,greater<pii> >q;
vector<pii> a[30005];
int n,m,k;
int in[30005];
int vis[30005];
int ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u].push_back({w,v});
		a[v].push_back({0,u});
		in[u]++;
		in[v]++;
	}
	int x=n;
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		x++;
		a[x].push_back({c,x+1});
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			a[i].push_back({0,x});
			a[x+1].push_back({w,i});
			in[i]++;
		}
		x++;
	}
	int mi=1e9;
	int b=0;
	for(int i=1;i<=n;i++){
		if(mi>in[i]){
			mi=in[i];
			b=i;
		}
	}
//	cout<<b;
	for(int i=0;i<a[b].size();i++){
		q.push({a[b][i].first,a[b][i].second});
	}
	while(!q.empty()){
		int w=q.top().first;
		int v=q.top().second;
		q.pop();
		if(vis[v]==0){
			ans+=w;
			for(int i=0;i<a[v].size();i++){
				q.push({a[v][i].first,a[v][i].second});
			}
//			cout<<v<<' '<<w<<'\n';
			vis[v]=1;
		}
	}
	cout<<ans;
	return 0; 
}
