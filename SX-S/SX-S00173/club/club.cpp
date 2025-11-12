#include <bits/stdc++.h>
using namespace std;
int t, n, na, nb, nc;
long long ans;

struct st {
	int a, b, c;
	int cha;
	int q;
} s[100010];
int d[100010];

int qu(int j) {
	int k = 1;
	for (int i = 1; i <= n; i++) {
		if (s[i].q == j)
			d[k++] = s[i].cha;
	}
	k--;
	sort(d + 1, d + k + 1);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	for (int kk = 1; kk <= t; kk++) {
		ans = 0;
		na = 0, nb = 0, nc = 0;
		//Çå¿Õ

		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &s[i].a, &s[i].b, &s[i].c);
			if (s[i].a >= s[i].b && s[i].b >= s[i].c) {//abc
				ans = ans + s[i].a;
				na++;
				s[i].q = 1;
				s[i].cha = s[i].a - s[i].b;
			} else if (s[i].a >= s[i].c && s[i].c >= s[i].b) {//acb
				ans = ans + s[i].a;
				na++;
				s[i].q = 1;
				s[i].cha = s[i].a - s[i].c;
			} else if (s[i].b >= s[i].a && s[i].a >= s[i].c) {//bac
				ans = ans + s[i].b;
				nb++;
				s[i].q = 2;
				s[i].cha = s[i].b - s[i].a;
			} else if (s[i].b >= s[i].c && s[i].c >= s[i].a) {//bca
				ans = ans + s[i].b;
				nb++;
				s[i].q = 2;
				s[i].cha = s[i].b - s[i].c;
			} else if (s[i].c >= s[i].a && s[i].a >= s[i].b) {//cab
				ans = ans + s[i].c;
				nc++;
				s[i].q = 3;
				s[i].cha = s[i].c - s[i].a;
			} else {//cba
				ans = ans + s[i].c;
				nc++;
				s[i].q = 3;
				s[i].cha = s[i].c - s[i].b;
			}
		}
		if (na > n / 2) {
			qu(1);
			for (int j = 1; j <= na - n / 2; j++) {
				ans -= d[j];
			}
		}
		if (nb > n / 2) {
			qu(2);
			for (int j = 1; j <= nb - n / 2; j++) {
				ans -= d[j];
			}
		}
		if (nc > n / 2) {
			qu(3);
			for (int j = 1; j <= nc - n / 2; j++) {
				ans -= d[j];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}//ez