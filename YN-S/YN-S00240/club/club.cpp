#include <bits/stdc++.h>
using namespace std;

int read() {
	int k = 0, f = 1, c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (; isdigit(c); c = getchar())
		k = k * 10 + (c ^ 48);
	return k * f;
}

struct node {
	int sh[3];
	int d, z, x;
	int ch1, ch2;
	void init(int a, int b, int c) {
		sh[0] = a;
		sh[1] = b;
		sh[2] = c;
		if (a > b) {
			if (b > c) {
				d = 0;
				z = 1;
				x = 2;
			} else if (c > a) {
				d = 2;
				z = 0;
				x = 1;
			} else {
				d = 0;
				z = 2;
				x = 1;
			}
		} else {
			if (a > c) {
				d = 1;
				z = 0;
				x = 2;
			} else if (b > c) {
				d = 1;
				z = 2;
				x = 0;
			} else {
				d = 2;
				z = 1;
				x = 0;
			}
		}
		ch1 = sh[d] - sh[z];
		ch2 = sh[z] - sh[x];
	}
	bool operator <(const node &tp)const {
		if (ch1 == tp.ch1) {
			return ch2 > tp.ch2;
		}
		return ch1 > tp.ch1;
	}
} p[100005];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int s[3] = {0, 0, 0};
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			int a = read(), b = read(), c = read();
			p[i].init(a, b, c);
		}
		sort(p + 1, p + 1 + n);
		int ans = 0;
		int n2 = n / 2;
		for (int i = 1; i <= n; ++i) {
			if (s[p[i].d] < n2) {
				++s[p[i].d];
				ans += p[i].sh[p[i].d];
			} else if (s[p[i].z] < n2) {
				++s[p[i].z];
				ans += p[i].sh[p[i].z];
			} else {
				++s[p[i].x];
				ans += p[i].sh[p[i].x];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
//This is the first kachang in my life