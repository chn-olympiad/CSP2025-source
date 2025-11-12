#include <bits/stdc++.h>
using namespace std;
int Q, n;

struct node {
	int a, b, c, id, fr, lost;
} s[100005];

bool cmp(node a, node b) {
	return a.lost < b.lost;
}

inline int read() {

	int res = 0;
	char a;

	while (1) {
		a = getchar();

		if (!(a >= '0' && a <= '9'))
			return res;
		res *= 10;
		res += a - '0';

	}

}
int a, b, c, na, nb, nc, ans;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	cin >> Q;
	read();

	while (Q--) {
		n = read();
		ans = na = nb = nc = 0;

		for (int i = 1; i <= n; i++) {


			s[i].a = read();
			s[i].b = read();
			s[i].c = read();
			s[i].id = i;

			if (s[i].a >= s[i].b && s[i].a >= s[i].c) {
				s[i].fr = 1;
				na++;
				ans += s[i].a;
				s[i].lost = s[i].a - max(s[i].b, s[i].c);
			} else if (s[i].b >= s[i].a && s[i].b >= s[i].c) {
				s[i].fr = 2;
				nb++;
				ans += s[i].b;
				s[i].lost = s[i].b - max(s[i].c, s[i].a);
			} else {
				s[i].fr = 3;
				nc++;
				ans += s[i].c;
				s[i].lost = s[i].c - max(s[i].b, s[i].a);
			}
		}

		sort(s + 1, s + 1 + n, cmp);

		if (na > n / 2) {

			for (int i = 1; i <= n; i++) {

				if (na == n / 2)
					break;

				if (s[i].fr != 1)
					continue;
				ans -= s[i].lost;
				na--;

			}

		} else if (nb > n / 2) {

			for (int i = 1; i <= n; i++) {

				if (nb == n / 2)
					break;

				if (s[i].fr != 2)
					continue;
				ans -= s[i].lost;
				nb--;


			}

		} else if (nc > n / 2) {

			for (int i = 1; i <= n; i++) {

				if (nc == n >> 2)
					break;

				if (s[i].fr != 3)
					continue;
				ans -= s[i].lost;
				nc--;

			}

		}

		printf("%d\n", ans);

	}



	return 0;
}
