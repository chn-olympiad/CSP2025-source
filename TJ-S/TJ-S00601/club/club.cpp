#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forl(i, j, k) for(int (i) = (j); (i) <= (k); (i)++)
#define forr(i, j, k) for(int (i) = (j); (i) >= (k); (i)--)
#define er(a) cout << "err: " << (a) << '\n';
#define pii pair<int, int>
const int N = 1e5+5;
int T;
int n, ans;
int tn[3];  // <= n/2
//
//bool mmax(int a, int b, int c) {
//	return max(a, max(b, c));
//}
//bool mmin(int a, int b, int c) {
//	return min(a, min(b, c));
//}
//
struct node {
	int a, b, c;
} t[N];
//
//bool cmp(node p, node q) {
//	return mmax(p.a, p.b, p.c) > mmax(q.a, q.b, q.c);
//}
bool flag_A;

bool cmpA(node p, node q) {
	return p.a > q.a;
}

void dfs(int idx, int an, int bn, int cn, int res) {
	if (idx > n) {
		ans = max(ans, res);
		return;
	}
	if (an < n/2) {
		dfs(idx+1, an+1, bn, cn, res+t[idx].a);
	}
	if (bn < n/2) {
		dfs(idx+1, an, bn+1, cn, res+t[idx].b);
	}
	if (cn < n/2) {
		dfs(idx+1, an, bn, cn+1, res+t[idx].c);
	}
}

void solve() {
	flag_A = 1;
	ans = 0;
	cin >> n;
	forl(i, 1, n) {
		cin >> t[i].a >> t[i].b >> t[i].c;
		if (t[i].b != 0 || t[i].c != 0) flag_A = 0;
	}
	if (n <= 30) {
		dfs(1, 0, 0, 0, 0);
		cout << ans << endl;
		return;
	}
	if (flag_A) {
		sort(t+1, t+n+1, cmpA);
		forl(i, 1, n/2) {
			ans += t[i].a;
		}
		cout << ans << endl;
		return;
	}
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
//	T = 1;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}

/*
dp
tree
贪心
二分
线段树
数学 
*/
