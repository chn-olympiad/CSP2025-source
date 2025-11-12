#include <bits/stdc++.h>
using namespace std;

struct mg {
	int xb, l;
};
mg a[10000];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, ans = 0, sum = 0, max = 0;
	cin >> n;
	if (n < 3) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		a[i].xb = i;
		cin >> a[i].l;
	}
	if (n == 3)
		for (int i = 1; i <= 3; i++) {
			sum += a[i].l;
		}
	{
		for (int i = 1; i <= 3; i++) {
			max = a[i].l;
			if (max * 2 < sum)
				ans++;
		}
	}
	cout << ans % 998244353;
	return 0;
}
