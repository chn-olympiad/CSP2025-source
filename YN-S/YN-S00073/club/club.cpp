#include <bits/stdc++.h>
using namespace std;
//
const int N = 1e5 + 5;
const int mod = 998244353;
int n;
int t;


struct P {
	int a;
	int b;
	int c;
} d[N];

bool cmp_a(P x, P y) {//a b c
	if (x.a == y.a) {
		if (x.b == y.b) {
			return x.c > y.c;
		}

		return x.b > y.b;
	}

	return x.a > y.a;
}

bool cmp_b(P x, P y) {//b a c
	if (x.b == y.b) {
		if (x.a == y.a) {
			return x.c > y.c;
		}

		return x.a > y.a;
	}

	return x.a > y.a;
}

bool cmp_c(P x, P y) {//c a b
	if (x.c == y.c) {
		if (x.a == y.a) {
			return x.b > y.b;
		}

		return x.a > y.a;
	}

	return x.c > y.c;
}

int ans = 0;


void dfs(int na, int nb, int nc, int u, int sum) {
	if (u > n) {
		ans = max(ans, sum);
		return;
	}

	if (na + 1 <= n / 2) {
		dfs(na + 1, nb, nc, u + 1, sum + d[u].a);
	}

	if (nb + 1 <= n / 2) {
		dfs(na, nb + 1, nc, u + 1, sum + d[u].b);
	}

	if (nc + 1 <= n / 2) {
		dfs(na, nb, nc + 1, u + 1, sum + d[u].c);
	}

}

//1.0
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;

	while (t--) {
		ans = -1;
		cin >> n;
		bool sp_a = 1, sp_b = 1;

		for (int i = 1; i <= n; i++) {

			cin >> d[i].a >> d[i].b >> d[i].c;
			sp_a &= (d[i].b == 0 && d[i].c == 0);
		}

		if (sp_a) {
			sort(d + 1, d + 1 + n, cmp_a);
			int ans = 0;

			for (int i = 1; i <= n / 2; i++) {

				ans += d[i].a;
			}

			cout << ans;
			return 0;
		} else  {
			dfs(0, 0, 0, 1, 0);
			cout << ans;
		}

	}

	return 0;
}
