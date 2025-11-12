#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, flag, num, c, r;
ll a[1000];

int qread() {
	char cc = getchar();
	int x = 0, f = 1;
	while (cc < '0' || cc > '9') {
		if (cc == '-')
			f = -1;
		cc = getchar();
	}
	while (cc >= '0' && cc <= '9') {
		x = x * 10 + cc - '0';
		cc = getchar();
	}
	return x * f;
}

void qwrite(int nn) {
	if (nn >= 10)
		qwrite(nn / 10);
	putchar(nn % 10 + '0');
}

int cmp(ll aa, ll bb) {
	return aa > bb;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	n = qread();
	m = qread();
	for (int i = 1; i <= n * m; i++) {
		a[i] = qread();
	}
	flag = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == flag) {
			num = i;
			break;
		}
	}
	if (num % n == 0) {
		c = num / n;
		if (c % 2 == 0)
			r = 1;
		else
			r = n;
	}

	else {
		c = num / n + 1;
		if (c % 2 == 0)
			r = n - (num % n) + 1;
		else
			r = num % n;
	}
	qwrite(c);
	printf(" ");
	qwrite(r);
	return 0;
}
