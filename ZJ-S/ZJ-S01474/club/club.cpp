#include <bits/stdc++.h>

using namespace std;

struct Node {
	int f1, f2, f3;
} a[100005];
struct Node2 {
	int l1, l2, l3, val;
};
int t;
long long mx = 0;
Node2 g[100005][3];
int f[205][105][105][105];
void dfs(int x, int l1, int l2, int l3, long long sum, int n) {
	if (x == n + 1) {
		mx = max(mx, sum);
		return;
	}
	if (l1 < n / 2) {
		dfs(x + 1, l1 + 1, l2, l3, sum + a[x].f1, n);
	}
	if (l2 < n / 2) {
		dfs(x + 1, l1, l2 + 1, l3, sum + a[x].f2, n);
	}
	if (l3 < n / 2) {
		dfs(x + 1, l1, l2, l3 + 1, sum + a[x].f3, n);
	}
}
bool cmp(Node x, Node y) {
	return x.f1 > y.f1;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].f1 >> a[i].f2 >> a[i].f3;
		}
		mx = 0;
		if (n <= 30) {
			dfs(1, 0, 0, 0, 0, n);
			cout << mx << "\n";
		} else {
			sort(a + 1, a + n + 1, cmp);
			long long sum = 0;
			for (int i = 1; i <= n / 2; i++) {
				sum += a[i].f1;
			}
			for (int i = n / 2 + 1; i <= n; i++) {
				sum += a[i].f2;
			}
			cout << sum << "\n";
		}
//		memset(g, 0, sizeof(g));

	}
	return 0;
}