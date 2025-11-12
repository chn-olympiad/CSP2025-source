#include<bits/stdc++.h>
using namespace std;
const int N=1e4,M=1e6;
int n,m,k;
struct edge{
	int v,w;
};
vector<edge> e[N];

struct node{
	int x,y,w;
};
vector<node> q;

bool cmp(node a,node b){
	return a.w>b.w;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
		q.push_back({u,v,w});
	}
	int c,a;
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int i=1;i<=n;i++){
			cin>>a;
			e[n+i].push_back({i,a});
			e[i].push_back({n+i,a});
		}
	}
	
	sort(q.begin(),q.end(),cmp);
	int ans=0;
	for(int i=0;i<n-1;i++){
		ans+=q[i].w;
	}
	cout<<ans;
	
	
	return 0;
}