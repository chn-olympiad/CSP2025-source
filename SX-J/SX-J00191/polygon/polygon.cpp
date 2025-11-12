#include <bits/stdc++.h>
using namespace std;
int a[25];
bool flag = 0;

int bab(int s) {
	int ans = 0;
	for (int i = 1; i <= s; i++) {
		ans += i;
	}
	return ans;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] != 1)
			flag = 1;
		sum += a[i];
	}

	int ans = 0;
	if (n == 3) {
		if (sum > a[n] * 2)
			ans++;
		cout << ans;
	}
	if (flag == 0) {
		for (int i = 1; i <= n - 2; i++) {
			ans += i * bab(n - 1 - i);
//			cout << ans;
		}
	}
	cout << ans % 998 % 244 % 353;
	return 0;
}