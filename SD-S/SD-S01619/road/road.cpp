/*我们你所可以自慰的，想来想去，也还是所谓对于将来的希望。

希望是附丽于存在的，有存在，便有希望，有希望，便是光明。*/
// 25+(56+?)+总司令+玄学
// 今年怎么这么难啊 
// 也许等不到 NOIP了 
// 我还是新高一啊，我不想退役啊 
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int N=1e4+15;
int n,m,k,c[15],d[N];
bitset<N> vis;
priority_queue<tuple<ll,int,int>> pq;
vector<pair<int,ll>> G[N],tr[N];
inline ll prim(){
	ll ans=0;int cnt=0;
	pq.emplace(0,0,1);
	while(cnt<n){
		ll W=-get<0>(pq.top());
		int u=get<1>(pq.top());
		int v=get<2>(pq.top());
		pq.pop();
		if(vis[v]) continue;
		vis[v]=1,ans+=W,++d[u],++d[v];
		cnt+=v<=n;
		tr[u].emplace_back(v,W),tr[v].emplace_back(u,W);
		for(const auto& e:G[v]){
			int p=e.first;ll w=e.second;
			if(vis[p]) continue;
			if(p>n&&!vis[p]) w+=c[p-n];
			pq.emplace(-w,v,p);
		}
	}
	return ans;
}
#ifdef __linux__
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc _getchar_nolock
#define pc _putchar_nolock
#endif
inline int read(){
	int n=0;char c=gc();
	while(!isdigit(c)) c=gc();
	while(isdigit(c)) n=(n<<1)+(n<<3)+(c&15),c=gc();
	return n;
}
inline void write(int n){
	static char sta[35],top=0;
	do sta[++top]=n%10; while(n/=10);
	while(top) pc(sta[top--]|48);
	return;
}
signed main(){
#ifdef __linux__
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
#endif
	n=read(),m=read(),k=read();
	for(int i=0,u,v,w;i<m;++i) u=read(),v=read(),w=read(),G[u].emplace_back(v,w),G[v].emplace_back(u,w);
	for(int i=1;i<=k;++i){
		c[i]=read();
		for(int j=1,w;j<=n;++j) w=read(),G[i+n].emplace_back(j,w),G[j].emplace_back(i+n,w);
	}
	ll ans=prim();
	for(int i=1;i<=k;++i) if(d[i+n]==1) ans-=tr[i+n][0].second;
	write(ans),pc('\n');
	return 0;
}
/*
     A            FFFFFFF      OOO
    A A           F           O   O
   A   A          FFFFFF     O     O
  AAAAAAA         F          O     O
 A       A        F           O   O
A         Away    F     rom    OOO  I
*/
