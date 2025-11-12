#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n,m,k;
struct Node{
	long long v;
	long long w;
	bool operator>(const Node a)const{
		return w>a.w;
	}
};
void prim(long long s,vector<vector<Node>> &g);
const long long N=100000+10;
long long ans=0;
long long c[N];
long long add=0;
vector<vector<Node>> tree(N);
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	vector<vector<Node>> g(n+1+k);
	vector<vector<Node>> b(n+1+k);
	
	for(int i=1;i<=m;i++){
		long long a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		g[a].emplace_back(Node{b,c});
		g[b].emplace_back(Node{a,c});
		
	}

	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		add+=c[i];
		for(int j=1;j<=n;j++){
			long long w;
			cin>>w;
			g[i+n].emplace_back(Node{j,w});
			g[j].emplace_back(Node{i+n,w});
		}
	}
	prim(1,g);

	cout<<ans+add;
	return 0;
}



void prim(long long s,vector<vector<Node>> &g){
	priority_queue<Node,vector<Node>,greater<Node>> q;
	bool st[N];
	long long dist[N];
	for(int i=0;i<=n+k;i++){
		st[i]=false;
	}
	for(int i=0;i<=n+k;i++){
		dist[i]=0X3F3F3F3F;
	}
	q.emplace(Node{s,0});
	dist[s]=0;
	
	while(!q.empty()){
		auto t=q.top();
		if(st[t.v]){
			q.pop();
			continue;
		}
		ans+=dist[t.v];
		st[t.v]=true;
		for(int i=0;i<g[t.v].size();i++){
			if(g[t.v][i].w<dist[g[t.v][i].v]&&!st[g[t.v][i].v]){
				dist[g[t.v][i].v]=g[t.v][i].w;
				tree[g[t.v][i].v].emplace_back(Node{t.v,g[t.v][i].w});
				tree[t.v].emplace_back(Node{g[t.v][i].v,g[t.v][i].w});
				q.emplace(Node{g[t.v][i].v,dist[g[t.v][i].v]});
			}
		}
	}
	
}


