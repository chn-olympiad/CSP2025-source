#include <bits/stdc++.h>
#define int long long
#define F(i, m, n) for(int i = m; i <= n; i++)
using namespace std;
struct P{
	int v1, v2, v3, w;
}a[100005];
struct N{
	int v, i, w;
}; 
void solve() {
	int n;
	cin >> n;
	vector<N> g;
	F(i, 1, n) {
		cin >> a[i].v1 >> a[i].v2 >> a[i].v3;
		a[i].w = min(a[i].v1, min(a[i].v2,a[i].v3));
		a[i].v1 -= a[i].w,a[i].v2 -= a[i].w,a[i].v3 -= a[i].w;
		g.push_back({a[i].v1, i, 1}),g.push_back({a[i].v2, i, 2}),g.push_back({a[i].v3, i, 3});
	}
	sort(g.begin(), g.end(), [](N x, N y) {
		if(x.v != y.v)return x.v > y.v;
		return a[x.i].w > a[y.i].w;
	});
	vector<bool> c(n+2);
	vector<int> p(4);
	int sum = 0, num = 0;
	for(auto m:g) {
		if(p[m.w] >= n/2||c[m.i])continue;
//		cout << m.v << ' ' << m.i << ' ' << m.w << '\n';
		sum+=m.v+a[m.i].w;
		p[m.w]++;
		c[m.i]=1;
		num++;
		if(num == n)break;
	}
	cout << sum;
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while(T--) {
		solve();
		cout << '\n';
	}
	return 0;
}