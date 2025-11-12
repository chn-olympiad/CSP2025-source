#include <bits/stdc++.h>
#define N 100005
using namespace std;
struct node {
	int a, b, c;
}p[N];
bool cmp(node l, node r) {
	int mxl = max(l.a, max(l.b, l.c));
	int mxr = max(r.a, max(r.b, r.c));
	if (mxl != mxr) {
		return mxl > mxr;
	}
	int mil = min(l.a, min(l.b, l.c));
	int mir = min(r.a, min(r.b, r.c));
	int midl, midr;
	if (l.a != mxl && l.a != mil)	midl = l.a;
	if (l.b != mxl && l.b != mil)	midl = l.b;
	if (l.c != mxl && l.c != mil)	midl = l.c;
	if (r.a != mxr && r.a != mir)	midr = r.a;
	if (r.b != mxr && r.b != mir)	midr = r.b;
	if (r.c != mxr && r.c != mir)	midr = r.c;
	if (midl != midr) {
		return midl < midr;
	} 
	return mil < mir;
}
struct node2 {
	int val, id;
}r[5];
bool cmp2(node2 l, node2 r) {
	return l.val > r.val;
}
int cl[5], ans, n;
void calc(int i) {
	r[1] = {p[i].a, 1};
	r[2] = {p[i].b, 2};
	r[3] = {p[i].c, 3};
	sort(r + 1, r + 3 + 1, cmp2);
	if (cl[r[1].id] < n / 2) {
		cl[r[1].id] ++;
		ans += r[1].val;
	} else if (cl[r[2].id] < n / 2) {
		cl[r[2].id] ++;
		ans += r[2].val;
	} else if (cl[r[3].id] < n / 2) {
		cl[r[3].id] ++;
		ans += r[3].val;
	}
}
int s,a[N];
void dfs(int deep) {
	if (deep == n + 1) {
		int c1 = 0, c2 = 0, c3 = 0, sum = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1) {
				c1 ++;
				sum += p[i].a;
			}
			if (a[i] == 2) {
				c2 ++;
				sum += p[i].b;
			}
			if (a[i] == 3) {
				c3 ++;
				sum += p[i].c;
			}
		}
		if (c1 > n / 2 || c2 > n / 2 || c3 > n / 2) return;
		s = max(s, sum);
		return;
	}
	a[deep] = 1;
	dfs(deep + 1);
	a[deep] = 2;
	dfs(deep + 1);
	a[deep] = 3;
	dfs(deep + 1);
}
void solve() {
	cin >> n;
	bool flagA = false;
	for (int i = 1; i <= n; i ++) {
		cin >> p[i].a >> p[i].b >> p[i].c;
		if (p[i].b != 0 || p[i].c != 0) {
			flagA = true;
		}
	}
	sort(p + 1, p + n + 1, cmp);
	if (flagA == false) {//A 5#
		int sum = 0;
		for (int i = 1; i <= n / 2; i ++) {
			sum += p[i].a;
		}
		cout << sum;
		return;
	}
	if (n <= 20) {
		dfs(1);
		cout << s << "\n";
		s = 0;
		return;
	} 
	for (int i = 1; i <= n; i ++) {
		calc(i);
	}
	cout << ans << "\n";
	ans = 0;
	for (int i = 1; i <= 3; i ++) cl[i] = 0;
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	int _;
	cin >> _;
	while (_ --) solve();
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
