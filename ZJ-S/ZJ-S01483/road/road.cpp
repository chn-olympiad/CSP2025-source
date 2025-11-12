#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+5;
int n,m,k,fa[N];
ll ans;
struct A{
	int u,v,w;
	bool operator < (const A & b) const{
		return w < b.w || w == b.w && u < b.u || w == b.w && u == b.u && v < b.v;
	}
};
set<A> e;
int find(int x){
	return x == fa[x]? x:find(fa[x]);
}
ll f(){
	int cnt = 1;
	ll sum = 0;
	for (int i = 1;i <= n + k + 1;++ i){
		fa[i] = i;
	}
	for (auto i:e){
		int u = i.u,v = i.v,w = i.w;
		int fu = find(u),fv = find(v);
		if (fu != fv){
			cnt ++;
			sum += w;
		}
		if (cnt >= n + k){
			return sum;
		}
	}
	return sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for (int i = 1;i <= m;++ i){
		int u,v,w;
		cin>>u>>v>>w;
		e.insert({u,v,w});
	}
	for (int i = 1;i <= k;++ i){
		int x;
		cin>>x;
		ans += x;
		for (int j = 1;j <= n;++ j){
			int w;
			cin>>w;
			e.insert({i + n,j,w});
		}
	}
	cout<<ans + f();
	return 0;
}