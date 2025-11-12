#include<bits/stdc++.h>
using namespace std;
#define ft first
#define sd second
typedef long long ll;
typedef vector<ll> vel;
typedef pair<ll,ll> pll;
typedef vector<pll> velp;
typedef pair<ll,pll> plpll;
typedef vector<vel> vevel;
typedef vector<velp> vevelp;
typedef vector<plpll> veplpll;
typedef priority_queue<ll,vel,greater<ll>> pqlg;
typedef priority_queue<pll,velp,greater<pll>> pqpllg;
typedef priority_queue<plpll,veplpll,greater<plpll>> pqplpllg;
ll n,m,k;
vel c;
vel cnt,qu;
vevelp g;
vector<bool> b;
ll ans=INT64_MAX;
void dfs(ll x,ll sum){
	if(x>k){
		ll anss=sum;
		vector<bool> vis(n+k+3);
		pqpllg q;
		vis[1]=1;
		for(auto i:g[1]){
			q.push({i.sd,i.ft});
		}
		while(!q.empty()){
			auto qt=q.top();
			q.pop();
			if(vis[qt.sd]||qt.sd>n&&b[qt.sd-n]==0)continue;
			sum+=qt.ft;
			vis[qt.sd]=1;
			for(auto i:g[qt.sd]){
				if(vis[i.ft]||i.ft>n&&b[i.ft-n]==0)continue;
				q.push({i.sd,i.ft});
			}
		}
		ans=min(ans,sum);
		return ;
	}
	dfs(x+1,sum);
	b[x]=1;
	dfs(x+1,sum+c[x]);
	b[x]=0;
}
void slv(){
	cin>>n>>m>>k;
	c=vel(k+3);
	cnt=qu=vel(k+3);
	g=vevelp(n+k+3);
	b=vector<bool>(k+3);
	for(int i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	bool b=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)b=0;
		for(int j=1;j<=n;j++){
			ll x;
			cin>>x;
			g[j].push_back({i+n,x});
			g[i+n].push_back({j,x});
			if(x!=0)b=0;
		}
	}
	if(b){
		cout<<0<<'\n';
		return ;
	}
	dfs(1,0);
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll T=1;
	while(T--){
		slv();
	}
	return 0;
}