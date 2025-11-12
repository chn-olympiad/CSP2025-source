#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename T>inline void read(T &n);
const int N=1e4+100;
const int INF=2e9;
struct edge{
	int v,w;
};
struct node{
	int id,dis;
	bool operator < (const node &b) const{
		return this->dis>b.dis;
	}
};
ll ans=1e18;
int n,k;
vector<edge>e[N];
int cost[15][N];
int c[15];
int dis[N];
bitset<N>mst,now;
priority_queue<node>pq;
ll prim(){
	ll ans=0;
	for (int i=1;i<=n+k;i++) dis[i]=INF;
	mst.reset();
	dis[1]=0;pq.push({1,0});
	while (!pq.empty()){
		int u=pq.top().id;
		pq.pop();
		if (u>n&&!now[u]) continue;//不在本轮考虑范围内 
		if (mst[u]) continue;
		mst[u]=1;
		ans+=dis[u]*1ll;
		for (auto it:e[u]){
			int v=it.v,w=it.w;
			if (w<dis[v]){
				dis[v]=w;
				pq.push({v,dis[v]});
			}
		}
	}
	return ans;
}
bool isA=1;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m;
	read(n),read(m),read(k);
	for (int u,v,w,i=1;i<=m;i++){
		read(u),read(v),read(w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for (int i=1;i<=k;i++){
		read(c[i]);
		if (c[i]>0) isA=0;
		for (int j=1;j<=n;j++){//建造乡镇的后连边的费用 
			read(cost[i][j]);
			e[i+n].push_back({j,cost[i][j]});
			e[j].push_back({i+n,cost[i][j]});
		}
	}
	if (isA){
		for (int i=1;i<=k;i++) now[i+n]=1;
		ans=prim();
		printf("%lld",ans);
	}else{
		for (int s=0;s<=(1<<k)-1;s++){
			now.reset();
			ll nw=0;
			int t=s,i=1;
			while (t){
				if (t&1) now[n+i]=1,nw+=c[i]*1ll;
				i++;t>>=1;
			}
			ans=min(ans,prim()+nw);
		}
		printf("%lld",ans);
	}
	
	return 0;
 }
template<typename T>inline void read(T &n){
	n=0;char c;
	T f=1;
	do{
		c=getchar();
		if (c=='-') f=-1;
	}while (c>'9'||c<'0');
	while (c>='0'&&c<='9'){
		n=(n<<1)+(n<<3)+(c^48);
		c=getchar();
	}
	n*=f;
}

