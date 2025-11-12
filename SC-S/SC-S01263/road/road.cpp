#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e6+1e5+5;
const int N=1e4+5;
int n,m,k;
int f[N],siz[N];
struct node{
	int u,v;
	ll w;
	node():u(0),v(0),w(0){}
	node(int U,int V,ll W):u(U),v(V),w(W){}
	bool operator<(const node &p) const {
		return w<p.w;
	}
}edge[M];
void init(){
	for(int i=1;i<=n;i++) f[i]=i,siz[i]=1;
}
int fd(int x){
	if(f[x]==x) return x;
	f[x]=fd(f[x]);
	return f[x];
}
inline void mg(int x,int y){
	f[y]=x;siz[x]+=siz[y];siz[y]=0;
}
void solve1(){
	sort(edge+1,edge+m+1);
	ll ans=0;
	for(int i=1;i<=m;i++){
		int u=edge[i].u,v=edge[i].v;
		ll w=edge[i].w;
		int x=fd(u),y=fd(v);
		if(x==y) continue;
		mg(x,y);ans+=w;
		if(siz[x]==n) break;
	}
	cout<<ans;
	return ;
}
ll a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	init();
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;cin>>u>>v>>w;
		edge[i]=node(u,v,w);
	}
	if(k==0){
		solve1();
		return 0;
	}
	int cnt=m;
	for(int i=1;i<=k;i++){
		int x;cin>>x;
		int loc=0;
		for(int j=1;j<=n;j++){
			cin>>a[j];if(a[j]==0) loc=j;
		}
		for(int j=1;j<=n;j++){
			if(j==loc) continue;
			edge[++cnt]=node(loc,j,a[j]);
		}
	}
	m=cnt;
	sort(edge+1,edge+m+1);
	ll ans=0;
	for(int i=1;i<=m;i++){
		int u=edge[i].u,v=edge[i].v;
		ll w=edge[i].w;
		int x=fd(u),y=fd(v);
		if(x==y) continue;
		mg(x,y);ans+=w;
		if(siz[x]==n) break;
	}
	cout<<ans;
	return 0;
}