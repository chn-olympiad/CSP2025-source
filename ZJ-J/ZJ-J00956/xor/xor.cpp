#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define pb push_back
#define edl cout << '\n';
#define debug cout << '*';
const int N= 5e5+10;
const int M= (1<<20)+15;
const int maxbit = 19;
int a[N];
int p[N];
vector <int> g[M];
int f[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) p[i] = p[i-1]^a[i];
	rep(i, 1, n) g[p[i]].pb(i);
	rep(i, 1, n) {
		int t = p[i-1]^k;
//		cout << t << ' ';
		//cong g[t] zhong zhao
//		pos = lowerbound(g[t].begin(), g[t].end(), i) - g[t].begin();
		if (g[t].size()==0) {
			f[i] = n+1;
			continue;
		}
		int l = 0, r = (int)g[t].size()-1;
		while (l < r) {
			int m = l + r >> 1;
			if (g[t][m] < i) l = m + 1;
			else r = m;
		}
		if (l >= g[t].size()||g[t][l]<i) {
			f[i] = n+1;
			continue;			
		}
		
		int pos = g[t][l];
		f[i] = pos;
	}
//	edl
//	rep(i, 1, n) cout << f[i] << ' ';edl
	int l = 1;
	int bar = n+1;
	int cnt = 0;
	while (l <= n) {
//		cout << l << ' ' << bar << '\n';
		if (f[l] > n) {
			l ++;
			continue;
		}
		while (l <= n && l < bar) {
			bar = min(bar, f[l]);
			l ++;
		}
		l = bar + 1;
		bar = n+1;
		cnt ++;
	}
	cout << cnt;
	return 0;
}
