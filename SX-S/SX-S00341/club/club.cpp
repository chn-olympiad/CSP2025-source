#include <bits/stdc++.h>
using namespace std;

struct va {
	int a;
	int b;
	int c;
} a[100010];

bool cmp(const va &x, const va &y) {
	return x.a > x.b;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		int n, ans = 0, k = 0;
		queue<int>q;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i].a >> a[i].b >> a[i].c;
		}
		sort(a + 1, a + n + 1, cmp);
		for (int i = 1; i <= n; ++i) {
			if (k <= n / 2) {
				q.push(a[i].a);
				k++;
			}
		}
		while (!q.empty()) {
			ans += q.front();
			q.pop();
		}
		cout << ans << "\n";
	}
	return 0;
}
