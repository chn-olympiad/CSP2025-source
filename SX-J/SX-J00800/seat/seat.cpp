#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool cmp(ll a, ll b) {
	return a > b;
}
ll n, m;
ll a[105];
ll flag, cnt;
ll num1, num2;

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	flag = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++)
		if (a[i] == flag) {
			cnt = i;
			break;
		}
	num1 = cnt % n;
	num2 = cnt / n;
	if (num1 == 0) {
		cout << num2 << ' ';
		if (num2 % 2 == 1)
			cout << n;
		else
			cout << 1;
	} else {
		cout << num2 + 1 << ' ';
		if ((num2 + 1) % 2 == 0)
			cout << n - num1 + 1;
		else
			cout << num1;
	}
	// 100 99 98 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 81
	return 0;
}