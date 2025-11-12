#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int, int> pii;

const int mod = 998244353;
const int N = 5010;
int n, a[N], ans, ma, c[N];
bool b[N];
ll sum;
map<string, int> m;

inline void dfs(int i) {
	if (i == n + 1) {
		return;
	}
	if (i >= 3) {
		string t = "";
		for (int j = 1; j <= n; j++)
			if (b[j]) t += (char)j;
		if (sum > ma * 2 && m[t] == 0) { ++ans; m[t] = 1; ans %= mod; }
	}
	for (int j = 1; j <= n; j++)
		if (!b[j] && a[j] >= c[i]) {
			b[j] = 1; c[i + 1] = a[j], sum += a[j]; int t = ma; ma = max(ma, a[j]);
			dfs(i + 1);
			b[j] = 0; sum -= a[j]; ma = t;
		}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	dfs(0);
	printf("%d\n", ans);
	return 0;
}
