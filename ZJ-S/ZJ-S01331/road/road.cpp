#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e4+15;
ll n,m,k,zw,ans=LLONG_MAX,a[15][N],fa[N];
struct edge{
	ll x,y,dis;
	bool operator<(const edge&o)const{
		return dis<o.dis;
	}
};
vector<edge> e,G,tmp;
//ll dis[N];
//bool vis[N];
//void prim(){
//	memset(dis,0x3f,sizeof dis);
//	priority_queue<node,vector<node>,greater<node> > q;
//	q.push({1,0});
//	while(q.size()){
//		node u=q.top();
//		q.pop();
//		if(vis[u.x]) continue;
//		vis[u.x]=1;
//		for(auto v:G[u.x]){
//			if(dis[v.x]>dis[u.x]+v.dis){
//				dis[v.x]=dis[u.x]+v.dis;
//				q.push({v.x,dis[v.x]});
//			}
//		}
//	}
//}//º¿ÃÏ 
ll find(ll x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
inline void scs(int AC){
	G.clear();
	for(auto i:e) G.push_back(i);
	for(auto i:tmp) G.push_back(i);
	for(int i=1;i<=n+k;i++) fa[i]=i;
	sort(G.begin(),G.end());
	ll res=0,cnt=0;
	for(int i=0;i<G.size();i++){
		ll u=G[i].x,v=G[i].y,w=G[i].dis;
		if(find(u)==find(v)) continue;
		cnt++;
		if(cnt==AC+n) break;
		fa[find(u)]=find(v);
		res+=w;
	}
//	cout<<res<<" "<<zw<<"\n";
	ans=min(ans,zw+res);
}
int main(){
	ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		ll x,y,z;cin>>x>>y>>z;
		e.push_back({x,y,z});
	}
	bool falg=0;
	for(int i=1;i<=k;i++){for(int j=0;j<=n;j++)	cin>>a[i][j];}
	for(int i=0;i<(1ll<<k);i++){
		zw=0;tmp.clear();
		for(int j=1;j<=k;j++){
			if(i&(1<<j-1)){
				zw+=a[j][0];
				for(int x=1;x<=n;x++){
					tmp.push_back({j+n,x,a[j][x]});
				}
			}
		}
		scs(__builtin_popcount(i));
	}
	cout<<ans;
	return 0;
}
