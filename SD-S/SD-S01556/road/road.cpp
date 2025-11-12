#include<bits/stdc++.h>
#define ll long long
using namespace std;
queue<ll>q;
ll n,m,k,cnt,ans=1e18;
ll dis[1010],vis[1010];
vector<pair<ll,ll> > v[1r010],t[1010];
struct node{
	int c,x,y,z;
};
struct edge{
	int f,add;
};
node c[110];
edge a[100010];
void diss(ll p){
	memset(dis,0x3f,sizeof dis);
	q.push(p);dis[p]=0;
	while(!q.empty()){
		ll x=q.front();q.pop();
		for(ll j=0;j<v[x].size();j++){
			pair<ll,ll> u=v[x][j];
			if(dis[x]+u.second<dis[u.first]){
				dis[u.first]=dis[x]+u.second;
				a[u.first].f=x;
				a[u.first].add=u.second;
				q.push(u.first);
			}
		}
	}
}
int dfs_(int x){
	if(vis[x]) return 0;
	vis[x]=1;
	if(a[x].f==1) return a[x].add;
	return a[x].add+dfs_(a[x].f);
}
void solve(int p){
	cnt=0;
	swap(t,v);
	for(int i=1;i<=k;i++){
		if(p>>i&1){
			cnt+=c[i].c;
			v[c[i].x].push_back({c[i].y,c[i].z}); //f[c[i].x].push_back((node){0,0,0,0});
			v[c[i].y].push_back({c[i].x,c[i].z}); //f[c[i].y].push_back((node){0,0,0,0});
		}
	}
	diss(1);
	memset(vis,0,sizeof vis);
	for(int i=1;i<=n;i++){
		cnt+=dfs_(i);
	}
	ans=min(ans,cnt);
	for(int i=1;i<=n;i++) v[i].clear();
	swap(v,t);
}
void dfs(ll q,ll p){
	if(q==n+1){
		solve(p);
		return;
	}
	dfs(q+1,p<<1+1);
	dfs(q+1,p<<1+0);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	while(m--){
		ll x,y,z;
		cin>>x>>y>>z;
		v[x].push_back({y,z}); //f[x].push_back((node){0,0,0,0});
		v[y].push_back({x,z}); //f[y].push_back((node){0,0,0,0});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i].c>>c[i].x>>c[i].y>>c[i].z;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
