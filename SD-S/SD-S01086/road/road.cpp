#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 10005, M = 1e6 + 2e5;
struct St{
	int u, v, w;
} a[M];
int fa[N];
int Find(int t){
	return (fa[t] == t ? fa[t] : fa[t] = Find(fa[t]));
} 
bool cmp(St a, St b){
	return a.w < b.w;
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	int sum = 0, t;
	for (int i = 1; i <= n; ++i) fa[i] = i;
	for (int i = 1; i <= m; ++i) cin >> a[i].u >> a[i].v >> a[i].w;
	sort(a + 1, a + m + 1, cmp);
	for (int i = 1; i <= m; ++i){
		int u = Find(a[i].u), v = Find(a[i].v);
		if (u != v){
			fa[u] = v;
			sum += a[i].w;
		}
	}
	cout << sum;
}


