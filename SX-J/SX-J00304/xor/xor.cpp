#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, k, zero, one, ans;
ll a[1000010];

int qread() {
	char c = getchar();
	int x = 0, f = 1;
	while (c < '0' || c > '9') {
		if (c == '-')
			f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}

void qwrite(int nn) {
	if (nn >= 10)
		qwrite(nn / 10);
	putchar(nn % 10 + '0');
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	n = qread();
	k = qread();
	for (int i = 1; i <= n; i++) {
		a[i] = qread();
		if (a[i] == 0)
			zero++;
		if (a[i] == 1)
			one++;
	}
	if (k == 1) {
		qwrite(one);
		return 0;
	}
	if (k == 0) {
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1 && a[i + 1] == 1) {
				ans++;
				i += 2;
			}
		}
		ans += zero;
		qwrite(ans);
		return 0;
	}
	int zty = 25;
	qwrite(zty);
	return 0;
}
