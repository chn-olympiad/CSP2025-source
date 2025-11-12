#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e4+10,M=1e6+10;
ll n,m,k,sum;
struct edge{
	ll u,v,w;
}e[M];
ll c[N],vis[N];
ll a[12][N];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		e[i].u=u,e[i].v=v,e[i].w=w;
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i];
//		cout<<c[i]<<" ";
		for(ll j=1;j<=n;j++){
			cin>>a[i][j];
//			if(a[i][j]==0) cout<<a[i][j]<<" ";
		}
//		cout<<"\n";
	}
	sort(e+1,e+1+m,cmp);
//	for(ll i=1;i<=m;i++){
//		cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<"\n";
//	}
	for(ll i=1;i<=n-1;i++){
		ll cost1=e[i].w,cost2=LLONG_MAX/2;
		ll u=e[i].u,v=e[i].v;
		for(ll j=1;j<=k;j++){
			cost2=min(cost2,c[j]+a[j][u]+a[j][v]);
		}
		sum+=min(cost1,cost2);
//		cout<<cost1<<" "<<cost2<<"\n";
	}
	cout<<sum<<"\n";
//	cout<<0<<"\n";
	return 0;
}
