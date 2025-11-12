#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define i128 _int128_t
#define endl "\n"
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 998244353;
const int MaxN = 1e9;
int maxn;
int sum = 0, n;
vi vit;
int a[5005];

bool cmp(int x, int y) {
	return x > y;
}

void dfs(int ans, int j, int dep) {
	if (j == n && dep >= 3)
		sum++;
	sum %= INF;
	for (int i = ans + 1; i <= n; i++) {
		if (vit[i])
			continue;
		if (ans + a[i] > maxn * 2)
			continue;
		vit[i] = 1;
		dfs(ans + a[i], i, dep + 1);
		vit[i] = 0;
		dfs(ans, i, dep);
	}
}

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	vit.assign(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		maxn = a[i];
		vit[i] = 1;
		dfs(0, 0, 1);
		vit[i] = 0;
		cout << sum << endl;
	}
	cout << sum;
	return 0;
}
