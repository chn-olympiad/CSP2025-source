#include <bits/stdc++.h>
#define iosFast ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define File(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout)
#define push_back emplace_back
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e5 + 10;
struct Node {
	int x, y, z;
} a[N];
int d[N], ans;
int n;
inline void dfs(int cur, int cx, int cy, int cz) {
	if (cur == n + 1) {
		int sum = 0;
		for (int i = 1; i <= n; i++)
			if (d[i] == 1) sum += a[i].x;
			else if (d[i] == 2) sum += a[i].y;
			else sum += a[i].z;
		ans = max(ans, sum);
	}
	if (cx + 1 <= n / 2) d[cur] = 1, dfs(cur + 1, cx + 1, cy, cz);
	if (cy + 1 <= n / 2) d[cur] = 2, dfs(cur + 1, cx, cy + 1, cz);
	if (cz + 1 <= n / 2) d[cur] = 3, dfs(cur + 1, cx, cy, cz + 1);
}
bool cmp(Node aa, Node bb) { return aa.x > bb.x; }
inline void solve() {
	cin >> n;
	bool A = true;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
		if (a[i].y != 0 || a[i].z != 0) A = false;
	}
	ans = INT_MIN;
	if (A) {
		ans = 0;
		sort(a + 1, a + n + 1, cmp);
		for (int i = 1; i <= n / 2; i++) ans += a[i].x;
	} else dfs(1, 0, 0, 0);
	
	cout << ans << endl;
}
signed main() {
	File("club");
	iosFast;
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}