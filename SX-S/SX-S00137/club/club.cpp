#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5+50;
ll t, n, a1, a2, a3, cha[N], est, b[4][N];

ll read() {
	ll s = 0, w = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			w = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		s = (s << 1) + (s << 3) + ch - '0';
		ch = getchar();
	}
	return s * w;
}

void write(ll x) {
	if (x < 0) {
		x = -x;
		putchar('-');
	}
	if (x <= 9)
		putchar(x + '0');
	else
		write(x / 10), putchar(x % 10 + '0');
	return ;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	t = read();
	for (ll i = 1; i <= t; i++) {
		ll ans = 0, ml, mm, num[4], numx;
		num[1] = 0;
		num[2] = 0;
		num[3] = 0;
		n = read();
		for (ll j = 1; j <= n; j++) {
			a1 = read();
			a2 = read();
			a3 = read();
			ml = max(max(a1, a2), a3);
			if (a1 == ml)
				b[1][++num[1]] = j, mm = max(a2, a3);
			else if (a2 == ml)
				b[2][++num[2]] = j, mm = max(a1, a3);
			else if (a3 == ml)
				b[3][++num[3]] = j, mm = max(a1, a2);
			ans += ml;
			cha[j] = ml - mm;
		}
		if (num[1] > n / 2)
			est = 1, numx = num[1];
		else if (num[2] > n / 2)
			est = 2, numx = num[2];
		else if (num[3] > n / 2)
			est = 3, numx = num[3];
		else {
			write(ans);
			putchar('\n');
			continue;
		}
		for (ll j = 1; j <= numx; j++)
			b[est][j] = cha[b[est][j]];
		sort(b[est] + 1, b[est] + numx + 1);
//		cout << num;
		ll cnt = 0;
		for (ll j = numx; j > n / 2; j--) {
			ans -= b[est][++cnt];
//			cout << ans << "!";
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}