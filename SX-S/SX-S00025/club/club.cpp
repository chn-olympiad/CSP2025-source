#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

int n;
int ans = 0;
int am, bm, cm;

struct node {
	int a, b, c;
} x[N];

bool cmp(node z, node y) {
	return z.a > y.a;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {

		cin >> n;
		for (int i = 1 ; i <= n ; i++) {
			cin >> x[i].a >> x[i].b >> x[i].c;
		}
		if (n == 2) {
			ans = max(ans, x[1].a + x[2].b);
			ans = max(ans, x[1].a + x[2].c);
			ans = max(ans, x[1].b + x[2].a);
			ans = max(ans, x[1].b + x[2].c);
			ans = max(ans, x[1].c + x[2].a);
			ans = max(ans, x[1].c + x[2].b);
		} else {
			sort(x + 1, x + 1 + n, cmp);
			for (int i = 1 ; i <= n / 2 ; i++) {
				ans += x[i].a;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}