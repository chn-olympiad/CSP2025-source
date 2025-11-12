#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double
template<typename T>

inline void read(T &x) {
	bool f = 1;
	x = 0;
	char ch;
	ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			f = !f;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + (ch - '0');
		ch = getchar();
	}
	x = (f ? x : -x);
	return ;
}
template<typename T>

inline void print(T x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9)
		print(x / 10);
	putchar(x % 10 + '0');
	return ;
}

const int N = 1e5+10;
int t, n, nn, num1, num2, num3, len, ans;
int a[N], b[N], c[N], maxx1[N], maxx2[N], kid[N], s[N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	read(t);
	for (int tt = 1; tt <= t; tt++) {
		len = ans = num1 = num2 = num3 = 0;
		read(n);
		nn = n / 2;
		for (int i = 1; i <= n; i++) {
			read(a[i]);
			read(b[i]);
			read(c[i]);
		}
		for (int i = 1; i <= n; i++) {
			maxx1[i] = max(a[i], max(b[i], c[i]));
			ans = ans + maxx1[i];
			if (maxx1[i] == a[i])
				maxx2[i] = max(b[i], c[i]), kid[i] = 1, num1++;
			else if (maxx1[i] == b[i])
				maxx2[i] = max(a[i], c[i]), kid[i] = 2, num2++;
			else if (maxx1[i] == c[i])
				maxx2[i] = max(a[i], b[i]), kid[i] = 3, num3++;
		}
		if (num1 <= nn && num2 <= nn && num3 <= nn) {
			printf("%d\n", ans);
			continue;
		}
		if (num1 > nn) {
			for (int i = 1; i <= n; i++)
				if (kid[i] == 1)
					s[++len] = maxx1[i] - maxx2[i];
		} else if (num2 > nn) {
			for (int i = 1; i <= n; i++)
				if (kid[i] == 2)
					s[++len] = maxx1[i] - maxx2[i];
		} else if (num3 > nn) {
			for (int i = 1; i <= n; i++)
				if (kid[i] == 3)
					s[++len] = maxx1[i] - maxx2[i];
		}
		sort(s + 1, s + len + 1);
		for (int i = 1; i <= len - nn; i++)
			ans = ans - s[i];
		printf("%d\n", ans);
	}
	return 0;
}
