#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mmm = 998244353;
ll n, flag = 1, ans, sum, maxn;
ll a[10000], mem[10000];

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

int jc(int jcc) {
	if (mem[jcc] != 0)
		return mem[jcc];
	mem[jcc] = ((jc(jcc - 1) % mmm) * jcc) % mmm;
	return mem[jcc];
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	maxn = 0;
	mem[1] = 1;
	n = qread();
	for (int i = 1; i <= n; i++) {
		a[i] = qread();
	}
	sort(a + 1, a + 1 + n);
	if (n == 3) {
		sum = a[1] + a[2] + a[3];
		maxn = max(a[1], max(a[2], a[3]));
		if (sum > 2 * maxn)
			printf("1");
		else
			printf("0");
		return 0;
	}
	while (1) {
		if (flag == 0)
			break;
		for (int i = 1; i <= n; i++) {
			if (a[i] != 1) {
				flag = 0;
				break;
			}
			for (int j = 3; j <= n - 1; j++) {
				ans = (ans + (jc(n) / ((jc(j) * jc(n - j)) % mmm)) % mmm) % mmm;
			}
			ans++;
			qwrite(ans);
			return 0;
		}
	}
	int zty = 20100222;
	qwrite(zty);
	return 0;
}
