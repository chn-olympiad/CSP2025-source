#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define inline
const ll N=2e6+10;
const ll inf=1e12;
ll n,m,k;
struct edge{
	int u,v,w;
};
vector<edge> g;
ll c[N];
ll a[20][N];
ll u[N],v[N],w[N];
bool cmp(edge x,edge y){
	return x.w<y.w;
}

ll fa[N];
ll find(ll a){
	if(fa[a]==0){
		return a;
	}
	fa[a]=find(fa[a]);
	return fa[a];
}
void he(ll a,ll b){
	fa[b]=a;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	ll anss=inf;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	bool fl=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		} 
	}
	if(k==0){
		ll ans=0;
		for(int i=1;i<=n+k;i++){
			fa[i]=0;
		}
		for(int i=1;i<=m;i++){
			g.pb({u[i],v[i],w[i]});
		}
		sort(g.begin(),g.end(),cmp);
		ll cnt=0;
		for(int i=0;i<g.size();i++){
			if(find(g[i].u)!=find(g[i].v)){
				cnt++;
				ans+=g[i].w;
				he(find(g[i].u),find(g[i].v));
			}
			if(cnt==n-1){
				break;
			}
		}
		cout<<ans<<"\n";
		return 0;
	}
	for(int o=0;o<(1<<k);o++){
		ll ans=0;
		g.clear();
		for(int i=1;i<=n+k;i++){
			fa[i]=0;
		}
		for(int i=1;i<=m;i++){
			g.pb({u[i],v[i],w[i]});
		}
		ll cnt=0;
		for(int i=1;i<=k;i++){
			if(o&(1<<(i-1))){
				ans+=c[i];
				cnt--;
				for(int j=1;j<=n;j++){
					g.pb({i+n,j,a[i][j]});
				}
			}
		}
		sort(g.begin(),g.end(),cmp);
		for(int i=0;i<g.size();i++){
			if(find(g[i].u)!=find(g[i].v)){
				cnt++;
				ans+=g[i].w;
				he(find(g[i].u),find(g[i].v));
			}
			if(cnt==n-1){
				break;
			}
		}
		anss=min(ans,anss);
	}
	cout<<anss<<"\n"; 
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4


*/

