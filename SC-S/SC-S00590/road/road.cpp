#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N = 1e6+5;
struct Edg {
	int u, v, w, nst;
} edg[N];
int n, m, head[N], len,k,vis[N],c[N];
vector<int> ne(10005,N*100),dis(10005,N*100);
struct Node{
	int di,dt;
	Node(int x,int y){
		di=x,dt=y;
	}
	bool operator<(const Node b)const{
		return dt>b.dt;
	}
};
void djs(int u){
	priority_queue<Node>q;
	q.push(Node(u,0));
	dis[u]=0;
	while(!q.empty()){
		int u=q.top().di;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];i;i=edg[i].nst){
			int v=edg[i].v;
			if(dis[v]>dis[u]+edg[i].w){
				dis[v]=dis[u]+edg[i].w;
				q.push(Node(v,dis[v]));
			}
		}
	}
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		edg[i]={u,v,w,head[u]};
		head[u]=i;
		swap(u,v);
		edg[i]={u,v,w,head[u]};
		head[u]=i;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			ne[i]=min(ne[i],x);		
		}
	}
    for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(i==j)continue;
			int u=j,v=i;
			edg[++m]={u,v,ne[u]+ne[v],head[u]};
			head[u]=m;
			swap(u,v);
			edg[++m]={u,v,ne[u]+ne[v],head[u]};
			head[u]=m;
		}
	}
	djs(1);
	int ans=0;
	if(k==1&&c[1]!=0){
		ans+=c[1];
	}
	for(int i=1;i<=n;i++){
		ans+=dis[i];
	}
	cout<<ans;
	return 0;
}