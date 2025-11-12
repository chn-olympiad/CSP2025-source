#include<bits/stdc++.h>
using namespace std;
const int M=1e6+100,N=1e4+10;

int n,m,k,sz=0;
int c[11];
struct Node{
	int u,v,w;
	bool operator < (const Node &rhs) const {
		return w<rhs.w ;
	}
}edge[M];
struct Edge{
	int u,v,w,op;
	bool operator < (const Edge &rhs) const {
		return w<rhs.w ;
	}
}edges[M+N];

int pa[N];
int find(int p) {
	return pa[p]==p? p:pa[p]=find(pa[p]);
}
void merge(int a,int b) {
	pa[find(a)]=find(b);
}
void init() {
	for(int i=1;i<N;i++) pa[i]=i;
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	init();
	long long ans=0;
	for(int i=1;i<=m;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		edge[i]={u,v,w};
	}
	sort(edge+1,edge+1+m);
	for(int i=1;i<=m;i++) {
		int u=edge[i].u ,v=edge[i].v ,w=edge[i].w ;
		if(find(u)==find(v)) continue;
		merge(u,v);
		ans+=w;
		edges[++sz]={u,v,w,0};
	}
	for(int i=1;i<=k;i++) {
		cin>>c[i];
		for(int j=1;j<=n;j++) {
			int a;
			cin>>a;
			edges[++sz]={n+i,j,a,i};
		}
	}
	sort(edges+1,edges+sz+1);
	for(int mark=0;mark<=(1<<k)-1;mark++) {
		init();
		long long res=0;
		for(int i=1;i<=sz;i++) {
			int u=edges[i].u ,v=edges[i].v ,w=edges[i].w ,op=edges[i].op ;
			if(op!=0&&(!(mark&(1<<(op-1))))) continue;
			if(find(u)==find(v)) continue;
			merge(u,v);
			res+=w;
		}
		for(int i=1;i<=k;i++) {
			if(mark&(1<<(i-1))) res+=c[i];
		}
		ans=min(ans,res);
	}
	cout<<ans<<"\n";
	return 0; 
}
