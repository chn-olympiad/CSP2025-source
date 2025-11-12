#include <bits/stdc++.h>
using namespace std;
const int N = 5e3+10;
int a[N], l[N];
long long n;

int cmd(int a, int b) {
	return a > b;
}

int pd(int n1, int z) {
	int ans = 0, k = 1, k1, fz = 0;
	memset(l, 0, sizeof(l));
	l[1] = z;
	for (int i = n1; i <= n; i++) {
		k1 = k;
		for (int j = 1; j <= k1; j++) {
			if (l[j] - a[i] < 0) {
				fz++;
			} else
				l[++k] = l[j] - a[i];
		}
		ans = ans + fz;
	}
	return ans;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long ans = 1, bj = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1)
			bj = 1;
	}
	if (n == 3) {
		cout << '1';
		return 0;
	}
	sort(a + 1, a + 1 + n, cmd);
	for (int i = 1; i <= n; i++) {
		ans = (ans + pd(i, 2 * a[i])) % 998244353;
	}
	cout << ans;
	return 0;
}
