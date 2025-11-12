#include<bits/stdc++.h>
using namespace std;

#define ll long long

namespace wjx{

int T_T = 1;

void IOS(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}

void FRE(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
}
int n,m,k;
ll c[15],a[15][1005];
int fa[1015];
int find(int x){
	if (fa[x] == x) return x;
	fa[x] = find(fa[x]);
	return fa[x];
}
struct Edges{
	int v;
	ll w;
};
vector <Edges> e[1005],g[1005];
struct EDGES{
	int u,v;
	ll w;
	bool operator < (EDGES other) const{
		return w > other.w;
	}
};
priority_queue <EDGES> vec,vc;
ll ans = 10000000000000;

void init(){
	ll sum = 0;
	for (int i = 1;i <= n + k;++i) fa[i] = i;
	int cnt = 0;
//	cout << "ASDFASDFASDF\n";
	while (!vc.empty()){
		int u = vc.top().u,v = vc.top().v;
		ll w = vc.top().w;
		vc.pop();
//		cout << u << ' ' << v << ' ' << sum << "\n";
		int fu = find(u),fv = find(v);
		if (fu != fv){
			sum += w;
			++cnt;
			vec.push((EDGES){u,v,w});
			fa[fu] = fv;
		}
	}
	vc = vec;
	ans = sum;
}

ll MCT(ll mx){
	ll sum = 0;
	for (int i = 1;i <= n + k;++i) fa[i] = i;
	int cnt = 0;
	while (!vec.empty()){
		int u = vec.top().u,v = vec.top().v;
		ll w = vec.top().w;
		vec.pop();
		int fu = find(u),fv = find(v);
		if (fu != fv){
			sum += w;
			++cnt;
			fa[fu] = fv;
		}
		if (sum > mx) return 10000000000000;
	}
	return sum;
}

void get(){
	cin >> n >> m >> k;
	for (int i = 1;i <= m;++i){
		int u,v;
		ll w;cin >> u >> v >> w;
		e[u].push_back((Edges){v,w});
		e[v].push_back((Edges){u,w});
		vc.push((EDGES){u,v,w});
	}
	for (int i = 1;i <= k;++i){
		cin >> c[i];
		for (int j = 1;j <= n;++j) cin >> a[i][j];
	}
}

void solve(){
//	cout << "ASDFASDFASDFASDF\n";
	init();
	for (int now = 1;now < (1 << k);++now){
		vec = vc;
		ll sum = 0;
		for (int i = 1;i <= k;++i)
			if (now & (1 << i - 1)){
				for (int j = 1;j <= n;++j) vec.push((EDGES){i + n,j,a[i][j]});
				sum += c[i];
			}
		ans = min(ans,MCT(ans - sum - 1) + sum);
//		cout << now << ' ' << ans << ' ' << sum << ' ' <<MCT(ans - sum) << "\n";
	}
	cout << ans << "\n";
}

signed main(){
//	cin >> T_T;
	while (T_T--){
		wjx::get();
		wjx::solve();
	}
	return 0;
}

} 

signed main(){
	wjx::IOS();
	wjx::FRE();
//	cout << 1024 * 110000 * __lg(110000);
	return wjx::main();
}
/*
1000000 * 20 = 20000000

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
