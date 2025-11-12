#include <bits/stdc++.h>

#define int long long

bool stmb;

using namespace std;

const int N = 100010;

int t, n;
int a[N][4];
long long ans;

template <typename type>
void read(type &res) {
	type x = 0, f = 1;
	char c = getchar();
	for (; c < 48 || c > 57; c = getchar()) f = (c == '-') ? -f : f;
	for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	res = f * x;
}

template <typename type, typename ...Args>
void read(type &x, Args &...args) {read(x), read(args...);}

void FileIO() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
}

namespace Subtask1 {
	bool check() {return n <= 10;}
	void dfs(int x, int c1, int c2, int c3, long long res) {
//		cerr << x << '\n';
		if (x > n) return void(ans = max(ans, res));
		if (c1 < n >> 1) dfs(x + 1, c1 + 1, c2, c3, res + a[x][1]);
		if (c2 < n >> 1) dfs(x + 1, c1, c2 + 1, c3, res + a[x][2]);
		if (c3 < n >> 1) dfs(x + 1, c1, c2, c3 + 1, res + a[x][3]);
	}
	void solve() {
		ans = 0;
		dfs(1, 0, 0, 0, 0);
		printf("%lld\n", ans);
	}
}

namespace Subtask2 {
	int A[N];
	bool check() {
		for (int i = 1; i <= n; i++) 
			if (a[i][2] || a[i][3]) 
				return false;
		return true;
	}
	void solve() {
		ans = 0;
		for (int i = 1; i <= n; i++) A[i] = a[i][1];
		sort(A + 1, A + 1 + n);
		for (int i = n; i > n >> 1; i--) ans += A[i];
		printf("%lld\n", ans);
	}
}

namespace Subtask3 {
	int c[N];
	bool check() {
		for (int i = 1; i <= n; i++) 
			if (a[i][3]) 
				return false;
		return true;
	}
	void solve() {
		ans = 0;
		for (int i = 1; i <= n; i++) ans += a[i][1];
		for (int i = 1; i <= n; i++) c[i] = a[i][2] - a[i][1];
		sort(c + 1, c + 1 + n);
		for (int i = n; i > n >> 1; i--) ans += c[i];
		printf("%lld\n", ans);
	}
}

namespace Subtask4 {
	int bb, cc;
	int C[N];
	bool v[N];
	struct node {
		int x, id;
		bool operator < (const node &Other) const {return x < Other.x;}
	} B[N];
	void solve() {
		cc = ans = 0;
		// 123
		long long res = 0;
		for (int i = 1; i <= n; i++) v[i] = 0;
		for (int i = 1; i <= n; i++) res += a[i][1];
		for (int i = 1; i <= n; i++) B[i] = {a[i][2] - a[i][1], i};
		sort(B + 1, B + 1 + n);
		for (int i = n; i > n >> 1; i--) {
			if (B[i].x < 0) break;
			bb++;
			res += B[i].x, v[B[i].id] = 1;
		}
		for (int i = 1; i <= n; i++) C[i] = a[i][3] - (v[i] ? a[i][2] : a[i][1]);
		sort(C + 1, C + 1 + n);
		for (int i = n; i; i--, cc++) {
//			if (C[i] <= 0) break;
			res += C[i];
			if (n - bb - cc <= n >> 1) ans = max(ans, res);
		}
		ans = max(ans, res);
//		cerr << res << ' ';
		// 132
		res = 0;
		for (int i = 1; i <= n; i++) v[i] = 0;
		for (int i = 1; i <= n; i++) res += a[i][1];
		for (int i = 1; i <= n; i++) B[i] = {a[i][3] - a[i][1], i};
		sort(B + 1, B + 1 + n);
		for (int i = n; i > n >> 1; i--) {
			if (B[i].x < 0) break;
			res += B[i].x, v[B[i].id] = 1;
		}
		for (int i = 1; i <= n; i++) C[i] = a[i][2] - (v[i] ? a[i][3] : a[i][1]);
		sort(C + 1, C + 1 + n);
		for (int i = n, cc = 0; cc < n >> 1; i--, cc++) {
			if (C[i] <= 0) break;
			res += C[i];
		}
		ans = max(ans, res);
//		cerr << res << ' ';
		// 213
		res = 0;
		for (int i = 1; i <= n; i++) v[i] = 0;
		for (int i = 1; i <= n; i++) res += a[i][2];
		for (int i = 1; i <= n; i++) B[i] = {a[i][1] - a[i][2], i};
		sort(B + 1, B + 1 + n);
		for (int i = n; i > n >> 1; i--) {
			if (B[i].x < 0) break;
			res += B[i].x, v[B[i].id] = 1;
		}
		for (int i = 1; i <= n; i++) C[i] = a[i][3] - (v[i] ? a[i][1] : a[i][2]);
		sort(C + 1, C + 1 + n);
		for (int i = n, cc = 0; cc < n >> 1; i--, cc++) {
			if (C[i] <= 0) break;
			res += C[i];
		}
//		cerr << res << ' ';
		ans = max(ans, res);
		// 231
		res = 0;
		for (int i = 1; i <= n; i++) v[i] = 0;
		for (int i = 1; i <= n; i++) res += a[i][2];
		for (int i = 1; i <= n; i++) B[i] = {a[i][3] - a[i][2], i};
		sort(B + 1, B + 1 + n);
		for (int i = n; i > n >> 1; i--) {
//			if (B[i].x < 0) break;
			res += B[i].x, v[B[i].id] = 1;
		}
		for (int i = 1; i <= n; i++) C[i] = a[i][1] - (v[i] ? a[i][3] : a[i][2]);
		sort(C + 1, C + 1 + n);
		for (int i = n, cc = 0; cc < n >> 1; i--, cc++) {
			if (C[i] <= 0) break;
			res += C[i];
		}
//		cerr << res << ' ';
		ans = max(ans, res);
		// 312
		res = 0;
		for (int i = 1; i <= n; i++) v[i] = 0;
		for (int i = 1; i <= n; i++) res += a[i][3];
		for (int i = 1; i <= n; i++) B[i] = {a[i][1] - a[i][3], i};
		sort(B + 1, B + 1 + n);
		for (int i = n; i > n >> 1; i--) {
			if (B[i].x < 0) break;
			res += B[i].x, v[B[i].id] = 1;
		}
		for (int i = 1; i <= n; i++) C[i] = a[i][2] - (v[i] ? a[i][1] : a[i][3]);
		sort(C + 1, C + 1 + n);
		for (int i = n, cc = 0; cc < n >> 1; i--, cc++) {
			if (C[i] <= 0) break;
			res += C[i];
		}
//		cerr << res << ' ';
		ans = max(ans, res);
		// 321
		res = 0;
		for (int i = 1; i <= n; i++) v[i] = 0;
		for (int i = 1; i <= n; i++) res += a[i][3];
		for (int i = 1; i <= n; i++) B[i] = {a[i][2] - a[i][3], i};
		sort(B + 1, B + 1 + n);
		for (int i = n; i > n >> 1; i--) {
			if (B[i].x < 0) break;
			res += B[i].x, v[B[i].id] = 1;
		}
		for (int i = 1; i <= n; i++) C[i] = a[i][1] - (v[i] ? a[i][2] : a[i][3]);
		sort(C + 1, C + 1 + n);
		for (int i = n, cc = 0; cc < n >> 1; i--, cc++) {
			if (C[i] <= 0) break;
			res += C[i];
		}
//		cerr << res << ' ';
		ans = max(ans, res);
//		cerr << '\n';
//		cerr << ans << ' ' << res << endl;
		printf("%lld\n", ans);
	}
}

void solve() {
	read(n);
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= 3; j++) 
			read(a[i][j]);
	if (Subtask1::check()) Subtask1::solve();
	else if (Subtask2::check()) Subtask2::solve();
	else if (Subtask3::check()) Subtask3::solve();
	else Subtask4::solve();
}

bool edmb;

signed main() {
//	cerr << (&stmb - &edmb) / 1024.0 / 1024.0 << '\n';
	FileIO();
	read(t);
	while (t--) solve();
	return 0;
}

/*
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
*/

