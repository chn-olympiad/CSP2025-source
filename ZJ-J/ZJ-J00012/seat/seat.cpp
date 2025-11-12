#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 105;
int n, m, num, tmp;
int a[N];
bool cmp(int x, int y) {
	return x > y;
}
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n * m; i++) scanf("%lld", &a[i]);
	num = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == num) num = i;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			tmp++;
			if (tmp == num) {
				printf("%lld %lld", i, j);
				return 0;
			}
		}
		i++;
		for (int j = n; j > 0; j--) {
			tmp++;
			if (tmp == num) {
				printf("%lld %lld", i, j);
				return 0;
			}
		}
	}
	return 0;
}