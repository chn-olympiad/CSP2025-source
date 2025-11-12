#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int N = 20030;
const int M = 1000005;

struct edge{
	int u, v;
	long long w;
	bool operator<(const edge& a)const{
		return w>a.w;
	}
};

struct node{
	int u, v, x;
}ns[12];

int nn;
int n, m, k, nsi=1;
bool flag=false;
long long c[12];
vector<edge> ks[12];
vector<edge> vs;

int fa[N], si[N], mn[N], mni[N];
int find(int x){
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void un(int u, int v){
	if(si[u]<si[v])swap(u, v);
	fa[v]=u;
	si[u]+=si[v];
	if(mn[u]>mn[v]){
		mn[u]=mn[v];
		mni[u]=mni[v];
	}
}
void def(int nx){
	priority_queue<edge> pq;
	for(int i=1; i<=n; i++){
		fa[i]=i;
		si[i]=1;
		mn[i]=ks[nx][i-1].w;
		mni[i]=i;
	}
	for(int i=1; i<nsi; i++){
		int u=ns[i].u, v=ns[i].v;
		un(u, ns[i].x);
		un(v, ns[i].x);
	}
	int len=vs.size();
	for(int i=0; i<len; i++){
		pq.push(vs[i]);
	}
	while(!pq.empty()){
		long long w=pq.top().w;
		int u=pq.top().u, v=pq.top().v;
		pq.pop();
		int x=find(u), y=find(v);
		if(si[x]==n)break;
		if(x==y)continue;
		if(x<=nn && y<=nn && c[nx]+mn[x]+mn[y] <= w){
			flag=true;
			ns[nsi++]={mni[x], mni[y], nx};
			//cout << u << ' ' << v << ' ' << c[nx]+mn[x]+mn[y] << ' ' << w << endl;
			return ;
		}
		un(x, y);
	}
}
long long solve(){
	long long ans=0;
	priority_queue<edge> pq;
	for(int i=1; i<=n; i++){
		fa[i]=i;
		si[i]=1;
	}
	int len=vs.size();
	for(int i=0; i<len; i++){
		pq.push(vs[i]);
	}
	while(!pq.empty()){
		long long w=pq.top().w;
		int u=pq.top().u, v=pq.top().v;
		pq.pop();
		int x=find(u), y=find(v);
		if(si[x]==n)break;
		if(x==y)continue;
		un(x, y);
		ans+=w;
	}
	return ans;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	nn=n;
	for(int i=1; i<=m; i++){
		long long w;
		int u, v;
		cin>>u>>v>>w;
		vs.push_back({u, v, w});
	}
	for(int i=1; i<=k; i++){
		cin>>c[i];
		for(int j=1; j<=n; j++){
			long long w;
			cin>>w;
			ks[i].push_back({j, n+i, w});
		}
	}
	long long ans=0;
	for(int i=1; i<=k; i++){
		flag=false;
		def(i);
		if(flag){
			ans+=c[i];
			int len=ks[i].size();
			for(int j=0; j<len; j++){
				vs.push_back(ks[i][j]);
			}
			n++;
		}
	}
	cout << ans + solve();
	return 0; 
}
