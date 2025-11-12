#include <bits/stdc++.h>
using namespace std;
char a[505];
int n, m;
int nai[505];
int ans = 1;
int ans1 = 1;
int ans2 = 2;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> nai[i];
	}
	if (n == m) {
		for (int i = 1; i <= n; i++) {
			if (n - 1 > 0)
				ans = ans * (n * (n - 1));
			n = n - 2;
		}
		cout << ans % 998244353;
	}
	/*else{
		for (int i = 1; i <= n; i++) {
			if (n - 1 > 0)
				ans1 = ans1 * (n * (n - 1));
			n = n - 2;
		}
		for (int i = 1; i <= m; i++) {
			if (m - 1 > 0)
				ans2 = ans2 * (m * (m - 1));
			m = m - 2;
		}
		ans=
	}*/
	return 0;
}
