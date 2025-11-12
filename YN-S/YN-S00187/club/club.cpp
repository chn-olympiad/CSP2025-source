#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int b[maxn];

struct s {
	int b, c, d;
} a[maxn];
int n;
long long sum = 0;

void dfs(int x, int e, int f, int g, long long ans) {
	if (x == n + 1) {
		sum = max(ans, sum);
		return ;
	}
	for (int i = 1; i <= 3; i++) {
		b[x] = i;
		if (i == 1) {
			e++;
			if (e > n / 2) {
				e--;
				continue;
			}
			ans += a[x].b;
			dfs(x + 1, e, f, g, ans);
			ans -= a[x].b;
			e--;
		}
		if (i == 2) {
			f++;
			if (f > n / 2) {
				f--;
				continue;
			}
			ans += a[x].c;
			dfs(x + 1, e, f, g, ans);
			ans -= a[x].c;
			f--;
		}
		if (i == 3) {
			g++;
			if (g > n / 2) {
				g--;
				continue;
			}
			ans += a[x].d;
			dfs(x + 1, e, f, g, ans);
			ans -= a[x].d;
			g--;
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		sum = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].b >> a[i].c >> a[i].d;
		}
		memset(b, 0, sizeof b);
		dfs(1, 0, 0, 0, 0);
		cout << sum << endl;
	}
	return 0;
}