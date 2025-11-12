#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define RFOR(i,a,b) for(int i=(a);i>=(b);i--)
typedef long long ll;
using namespace std;
#define int long long
int n,m,k,ans;
const int N=2e6+5;
struct edge{
	int u,v,w;
	bool operator < (const edge &x) const{
		return w<x.w;
	}
}e[N];
int c[15],a[15][10005];
int f[10005];
int findf(int x){
	return f[x]==x?f[x]:f[x]=findf(f[x]);
}
bool merge(int x,int y){
	int fx=findf(x),fy=findf(y);
	if(fx==fy) return 0;
	f[fx]=fy;
	return 1;
}
void solve1(){
	ans=0;
	for(int i=1;i<=n;i++) f[i]=i;
	sort(e+1,e+m+1);
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(merge(e[i].u,e[i].v)){
			cnt++;
			ans+=e[i].w;
		}
		if(cnt==n-1) break;
	}
	cout<<ans<<"\n";
}
void solve2(){
	ans=0;
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			e[++m]=(edge){n+i,j,a[i][j]};
		}
	}
	sort(e+1,e+m+1);
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(merge(e[i].u,e[i].v)){
			cnt++;
			ans+=e[i].w;
		}
		if(cnt==n+k-1) break;
	}
	cout<<ans<<"\n";	
}
int kruskal(int n,vector<edge>& edges,vector<edge>& result_edges){
	sort(edges.begin(),edges.end());
	for(int i=1;i<=n;i++) f[i]=i;
	int res=0,cnt=0;
	result_edges.clear();
	for(auto it:edges){
		int u=it.u,v=it.v,w=it.w;
		if(merge(u,v)){
			cnt++;
			res+=w;
			result_edges.push_back(it);
		}
		if(cnt==n-1) break;
	}
	return res;
}
void solve3(){
	vector<edge> origin_edge;
	for(int i=1;i<=m;i++){
		origin_edge.push_back({e[i].u,e[i].v,e[i].w});
	}
	vector<edge> base_mst;
	int base_cost=kruskal(n,origin_edge,base_mst);
	int min_cost=base_cost;
	for(int s=1;s<(1<<k);s++){
		vector<edge>current_edges=base_mst;
		int t_cost=0,t_cnt=0;
		for(int j=1;j<=k;j++){
			if(s&(1<<(j-1))){
				t_cnt++;
				t_cost+=c[j];
				for(int i=1;i<=n;i++){
					current_edges.push_back({i,n+j,a[j][i]});
				}
			}
		}
		vector<edge> tmp;
		int mst_cost=kruskal(n+t_cnt,current_edges,tmp);
		min_cost=min(min_cost,t_cost+mst_cost);
	}
	cout<<min_cost<<"\n";
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];	
	}
	int flag=1;
	for(int i=1;i<=k;i++){
		if(c[i]!=0){
			flag=0;
			break;
		}
		int minn=INF;
		for(int j=1;j<=n;j++) minn=min(minn,a[i][j]);
		if(minn!=0){
			flag=0;
			break;
		}
	} 
	if(k==0){
		solve1();
	}else if(flag==1){
		solve2();
	}else{
		solve3();
	}
	return 0;
}

