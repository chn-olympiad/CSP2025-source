#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e3+10;
const ll M=3e6+10;
ll n,m,k;
struct node{
	ll u,v,w;
}e[M];
ll val[10][N],cnt=0;
ll d[N][N];
bool cmp(node a,node b){
	return a.w<b.w;
}
ll fa[N];
ll Find(ll x){
	if(fa[x]==x) return x;
	return fa[x]=Find(fa[x]);
}
void solve1(){
	for(ll i=1;i<=n;i++)
		for(ll j=i+1;j<=n;j++) d[i][j]=1e9;
	for(ll i=1;i<=k;i++){
		for(ll x=1;x<=n;x++)
			for(ll y=x+1;y<=n;y++){
				d[x][y]=d[y][x]=min(d[x][y],val[i][x]+val[i][y]);
			}
				
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			e[++cnt]={i,j,d[i][j]};
//			cout<<i<<','<<j<<' '<<d[i][j]<<'\n';
		}
	}
	sort(e+1,e+cnt+1,cmp);
	ll tot=0,ans=0;
	for(ll i=1;i<=cnt;i++){
		ll x=e[i].u,y=e[i].v;
		ll fx=Find(x),fy=Find(y);
		if(fx==fy) continue;
		fa[fx]=fy;
		ans+=e[i].w,tot++;
		if(tot==n-1) break;
	}
	cout<<ans<<'\n';
}
void solve0(){
	sort(e+1,e+cnt+1,cmp);
	ll tot=0,ans=0;
	for(ll i=1;i<=cnt;i++){
		ll x=e[i].u,y=e[i].v;
		ll fx=Find(x),fy=Find(y);
		if(fx==fy) continue;
		fa[fx]=fy;
		ans+=e[i].w,tot++;
		if(tot==n-1) break;
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	bool flA=1;
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++) fa[i]=i;
	for(ll i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		e[++cnt]={u,v,w};
	}
	if(k==0){
		solve0();
		return 0;
	}
	for(ll i=1;i<=k;i++){
		ll c;
		cin>>c;
		if(c!=0) flA=0;
		for(ll j=1;j<=n;j++){
			cin>>val[i][j];
		}
	}
	if(flA){
		solve1();
		return 0;
	}
	return 0;
}
