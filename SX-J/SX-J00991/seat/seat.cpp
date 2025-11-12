#include <bits/stdc++.h>
using namespace std;
long long n, m, t, x, y;

struct Node {
	long long so, nu;
} a[110];

bool cmp(Node x1, Node x2) {
	return x1.so > x2.so;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n * m; i++) {
		scanf("%lld", &a[i].so);
		a[i].nu = i;
	}
	sort(a + 1, a + 1 + n *m, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i].nu == 1) {
			x = (i + n - 1) / n;
			if (x % 2 == 0) {
				y = n + 1 - (i - (n *(x - 1)));
			} else {
				y = i - (n *(x - 1));
			}
			printf("%lld %lld", x, y);
		}
	}
	return 0;
}
