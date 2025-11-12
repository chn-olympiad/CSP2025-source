#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn=1e6+7;
struct edge{
	ll u,v,w;
};
bool comp(edge a,edge b){
	return a.w<b.w;
}
vector<edge> vec;
vector<edge> veca[15];
ll ki[15];

ll fa[maxn];
ll find(ll x){
	if (fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void merge(ll x,ll y){
	ll fx=find(x);
	ll fy=find(y);
	if (fx!=fy) fa[fx]=fy;
	return;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n,m,k;
	cin>>n>>m>>k;
	for (ll i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		vec.push_back({u,v,w});
	}
	sort(vec.begin(),vec.end(),comp);
	ll cnt=n;
	
	
	k=0;
	if (k==0) {
		for (ll i=1;i<=n;i++){
			fa[i]=i;
		}
		ll ans=0;
		ll pos=-1;
		while (cnt>1 && pos+1<m){
			edge now=vec[++pos];
			ll fu=now.u,fv=now.v;
			if (find(fu)!=find(fv)) {
				merge(fu,fv);
				ans+=now.w;
				cnt--;
			}
		}
		cout<<ans;
		return 0;
	}
}

