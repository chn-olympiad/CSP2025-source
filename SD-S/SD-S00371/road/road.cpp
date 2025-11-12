#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back

const int N=1e6+10;
ll n,m,k,ans,w[N],fa[N],up[N];
bool c[N];

struct edge{
	int t;ll u;ll v;ll l;
};

vector<edge> t;

bool cmp(edge a,edge b){
	return a.l<b.l;
}

ll find(ll x){
	return fa[x]?fa[x]=find(fa[x]):x ;
}

signed main(){
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	ios;
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		ll u,v,l;
		cin >> u >> v >> l;
		t.pb({0,u,v,l});
	}
	for(int i=1;i<=k;i++){
		cin >> w[i];
		for(int j=1;j<=n;j++){
			ll d;
			cin >> d;
			if(j==i){
				up[i]=d;
			}
			t.pb({2,i,j,d+w[i]});
			t.pb({1,i,j,d});
		}
	}
	sort(t.begin(),t.end(),cmp);
	//for(int i=1;i<=m+k*n*2;i++){cout << t[i-1].t << ' ' << t[i-1].u << ' ' << t[i-1].v << ' ' << t[i-1].l << endl;}cout << endl;
	int sz=t.size();
	for(ll i=0;i<sz;i++){
		if(t[i].t==0){
			ll u=t[i].u,v=t[i].v;
			u=find(u);v=find(v);
			if(u!=v){
				ans+=t[i].l;
				fa[u]=v;
			}
		}
		if((t[i].t==1&&c[t[i].u])||(t[i].t==2&&!c[t[i].u])){
			ll u=t[i].u,v=t[i].v;
			u=find(u);v=find(v);
			if(u!=v){
				ans+=t[i].l;
				fa[u]=v;
				if(t[i].t==2){
					c[i]=1;
					ans+=up[u];
				}
				//cout << i << ' ' << ans << endl;
			}
		}
	}
	//cout << endl;
	cout << ans;
	return 0;
}


