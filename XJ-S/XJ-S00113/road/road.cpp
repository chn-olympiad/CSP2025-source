#include<bits/stdc++.h>
#define N 10015
#define int long long
using namespace std;

int n,m,k;
struct edge{
	int v,w;
};
vector<edge> e[N];
int vis[N],sum=0;
struct node{
	int x,w;
	friend bool operator<(const node &p,const node &q){
		return p.w<q.w;
	}
};
int c[15],a[15][N];

void ks(int s){
	priority_queue<node> q;
	q.push((node){s,0});
	while (!q.empty()){
		node tmp=q.top();q.pop();
		int nw=tmp.x;
		if (vis[nw]==1) continue;
		vis[nw]=1;
		for (edge eg:e[nw]){
			int v=eg.v,w=eg.w;
			if (vis[v]==1) continue;
			sum+=w;
			q.push((node){v,w});
		}
	}
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	while (m--){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back((edge){v,w});
		e[v].push_back((edge){u,w});
	}	
	for (int i=1;i<=k;++i){
		cin>>c[i];
		for (int i=1;i<=n;++i){
			cin>>a[i][j];
			e[n+i].push_back((edge){i,a[i][j]});
		}
	}	
	ks(1);
	cout<<sum;
/*	for (int i=n+1;i<=n+k;++i){
		sum=0;
		vis[i]=1;
		sum+=c[i];
		ks(1);
		ans=min(ans,sum);
	}*/
	return 0;
}
