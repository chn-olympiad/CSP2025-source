#include<bits/stdc++.h>
using namespace std;
long long n,m,k,f[20005],a[15][20005],anst,ansf;
struct Node{
	long long v,w;
};
bool flag[20005],chs[20005];
struct Edge{
	long long u,v,w;
	bool operator <(Edge x) const{
		return w>x.w;
	}
};
vector<Node> e[20005];
priority_queue<Edge,vector<Edge> > q;
vector<Edge> g,gtmp;
bool cmp(long long x,long long y){
	return a[x][0]<a[y][0];
}
long long find(long long x){
	if(f[x]==x){
		return x;
	}
	return f[x]=find(f[x]);
}
long long kruskal(long long n){
	long long res=0;
	for(long long i=1;i<=n;i++){
		f[i]=i;
	}
	while(!q.empty()){
		long long u=q.top().u,v=q.top().v,w=q.top().w;
		q.pop();
		if(find(u)==find(v)){
			continue;
		}
		f[find(u)]=find(v);
		gtmp.push_back({u,v,w});
		res=res+w;
	}
	return res;
}
void solve(){
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
		q.push({u,v,w});
	}
	anst=kruskal(n);
	for(Edge G:gtmp){
		g.push_back(G);
	}
	for(long long i=1;i<=k;i++){
		for(long long j=0;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(long long l=1;l<=k;l++){
		long long sds=-1;
		for(long long i=1;i<=k;i++){
			if(chs[i]){
				continue;
			}
			memset(flag,0,sizeof(flag));
			ansf=0;
			gtmp.clear();
			for(long long j=1;j<=n;j++){
				q.push({j,n+i,a[i][j]});
			}
			for(Edge G:g){
				q.push(G);
			}
			ansf=kruskal(n+k);
			for(Edge G:gtmp){
				long long u=G.u,v=G.v;
				if(u>n){
					flag[u-n]=true;
				}
				if(v>n){
					flag[v-n]=true;
				}
			}
			for(long long j=1;j<=k;j++){
				if(flag[j]){
					ansf=ansf+a[j][0];
				}
			}
			if(anst>ansf){
				anst=ansf;
				sds=i;
			}
		}
		if(sds==-1){
			break;
		}
		chs[sds]=true;
		gtmp.clear();
		for(long long j=1;j<=n;j++){
			q.push({j,n+sds,a[sds][j]});
		}
		for(Edge G:g){
			q.push(G);
		}
		kruskal(n+k);
		g.clear();
		for(Edge G:gtmp){
			g.push_back(G);
		}
	}
	cout<<anst<<"\n";
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long t=1;
	while(t--){
		solve();
	}
	return 0;
}
