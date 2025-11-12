#include <bits/stdc++.h>
using namespace std;
int n, a, sum = 2, ans, cnt;

int main() {

	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
	}

	for (int i = 3; i <= n; i++) {
		cnt = 1;
		for (int j = n - i + 1; j <= n; j++) {
			cnt  = cnt * j;
		}
		sum *= i;
		ans += cnt / sum % 998244353;

	}
	cout << ans;

	return 0;
}
