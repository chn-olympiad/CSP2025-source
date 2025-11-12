//
//  A  baoli 25
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define ull unsigned long long
#define PII pair<int, int>
#define itn int
#define ls(u) (u <<< 1)
#define rs(u) (u << 1 | 1)
using namespace std;

int T = 1;
const int N = 5e5 + 9;
int n, m;
struct node {
	int a, b, c;
	bool operator<(const node &_) const {
		if (a == _.a) {
			if (b == _.b) return c > _.c;
			else return b > _.b;
		}
		return a > _.a;		
	}	
}ww[N];
int ans;
int cnt[4];

inline void dfs(int x, int sum) {
	if (x == n + 1) {
		ans = max(ans, sum);
		return;
	}
	if (cnt[1] + 1 <= m) {
		cnt[1] ++;
//		cout << 1 << ' ';
		dfs(x + 1, sum + ww[x].a);
		cnt[1] --;
	}
	if (cnt[2] + 1 <= m) {
		cnt[2] ++;
//		cout << 2 << ' ';
		dfs(x + 1, sum + ww[x].b);
		cnt[2] --;
	}
	if (cnt[3] + 1 <= m) {
		cnt[3] ++;
		dfs(x + 1, sum + ww[x].c);
		cnt[3] --;
	}
}

inline void A() {
	int ans = 0;
	sort(ww + 1, ww + n + 1);
	for (int i = 1; i <= m; i ++) {
		ans += ww[i].a;
	}
}


inline void B() {
	int v1[N] = {0}, v2[N] = {0};
	for (int i = 1; i <= n; i ++) {
		v1[i] = ww[i].a, v2[i] = ww[i].b;
	}
	sort(v1 + 1, v1 + n + 1);
//	sort(v2 + 1, v2 + n + 1);
	
}

inline void solve() {
	cin >> n;
	m = n / 2;
	memset(cnt, 0, sizeof(cnt));
	memset(ww, 0, sizeof(ww));
	ans = 0;
	bool f2 = 1, f3 = 1;
	for (int i = 1; i <= n; i ++) {
		cin >> ww[i].a >> ww[i].b >> ww[i].c;
		if (ww[i].b != 0) f2 = 0;
		if (ww[i].c != 0) f3 = 0;
	}
	if (f2 == 1 && f3 == 1) {
		A();
	}
	else if (f3 == 1) {
		B();
	}
	else {
		dfs(1, 0);
	}
	cout << ans << '\n';
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

//	ios::sync_with_stdio(0);
//	cin.tie(0), cout.tie(0);

	cin >> T;
	while (T --) {
		solve();
	}

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


1
4
4 2 1
3 2 4
5 3 4
3 5 1

*/

