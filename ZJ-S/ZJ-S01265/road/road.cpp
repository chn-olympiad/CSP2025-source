#include<bits/stdc++.h>
using ll=long long;
using pii=std::pair<int,int>;
#define eb emplace_back
#define mkp std::make_pair
inline int read(){
	int X=0;char ch;bool f=0;
	do{ch=getchar();f|=(ch=='-');}while(!isdigit(ch));
	do{X=(X<<1)+(X<<3)+(ch^48);}while(isdigit(ch=getchar()));
	return f?-X:X;
}
const int N=1e4,M=1e6;
struct Edge{
	int u,v,w;
	Edge(){u=v=w=0;}
	Edge(int _u,int _v,int _w){u=_u;v=_v;w=_w;}
}E[N+15];
std::vector<pii> e[N+15];
int n,m,k;
std::priority_queue<pii,std::vector<pii>,std::greater<pii> > q;
int dist[N+15],pre[N+15];
std::bitset<N+15> vis;
pii tmp;
int c[15];
ll ans=1e16;
void check(bool type,ll cost){
	ll res=cost;int etot=0;
	for(int i=2;i<=n+k;i++) dist[i]=INT_MAX;
	q.push(std::make_pair(0,1));
	while(!q.empty()){
		tmp=q.top();q.pop();
		int u=tmp.second,c=tmp.first;
		if (vis.test(u)) continue;
		vis.set(u);res+=dist[u];
//		printf("%d ",dist[u]);
		if (type&&u!=1) E[++etot]=Edge(pre[u],u,dist[u]);
		for(int i=0;i<e[u].size();i++){
			tmp=e[u][i];
			int v=tmp.second,w=tmp.first;
			if (w>=dist[v]||vis.test(v)) continue;
			dist[v]=w;pre[v]=u;q.push(std::make_pair(w,v));
		}
	}
//	printf("%lld\n",res);
	ans=std::min(ans,res);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		e[u].eb(mkp(w,v));e[v].eb(mkp(w,u));
	}
	for(int i=n+1;i<=n+k;i++) vis.set(i);
	check(1,0);
	for(int i=1;i<=n;i++) e[i].clear();
	for(int i=1;i<n;i++){
		int u=E[i].u,v=E[i].v,w=E[i].w;
		e[u].eb(mkp(w,v));e[v].eb(mkp(w,u));
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int v=1;v<=n;v++){
			int u=i+n,w=read();
			e[u].eb(mkp(w,v));e[v].eb(mkp(w,u));
		}
	}
	for(int b=1;b<(1<<k);b++){
		vis.reset();ll cost=0;
		for(int i=0;i<k;i++){
			if (((b>>i)&1)==0) vis.set(n+i+1);
			else cost+=c[i+1];
		}check(0,cost);
	}printf("%lld\n",ans);
	return 0;
}
