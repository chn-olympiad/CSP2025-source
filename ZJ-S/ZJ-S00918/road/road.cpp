#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,mod=1e9+7,inf=0x3f3f3f3f;
int n,m,k,fa[N],c[15],a[15][N],u[N],v[N],w[N],d[N],s;
bool vis[N];
struct data{
	int n,i;
}cnt[N];
bool cmp(data x,data y){
	return x.n<y.n;
}
struct node{
	int to,w;
};
vector<node>g[N];
struct nodee{
	int d,du;
};
priority_queue<nodee>q;
bool operator<(const nodee &a,const nodee &b){
	return a.du>b.du;
}
void dij(){
	for(int i=1;i<=n;i++) d[i]=inf;
	q.push({s,0});
	d[s]=w[s];
	while(!q.empty()){
		int u=q.top().d;
		q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(auto e:g[u]){
			if(d[e.to]>d[u]+e.w){
				d[e.to]=d[u]+e.w;
				q.push({e.to,d[e.to]});
			}
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		g[u[i]].push_back({v[i],w[i]});
		g[v[i]].push_back({u[i],w[i]});
		cnt[u[i]].n++;
		cnt[v[i]].n++;
		cnt[u[i]].i=u[i];
		cnt[v[i]].i=v[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	if(k==0){
		sort(1+cnt,1+cnt+n,cmp);
		s=cnt[1].i;
		dij();
		int maxx=0;
		for(int i=1;i<=n;i++){
			maxx=max(d[i],maxx);
		}
		cout<<maxx;
		return 0;
	}
	return 0;
}
