#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int T, n;
struct node {
	int a, d;
} m[100010];

bool cmp(node x, node y) {
	return x.d < y.d;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		int cnt[4] = {0};
		int a, b, c;
		long long ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a, &b, &c);
			if (a >= b && a >= c) {
				m[i].a = 1;
				cnt[1]++;
				ans += a;
				if (b >= c)
					m[i].d = a - b;
				else
					m[i].d = a - c;
			} else if (b >= a && b >= c) {
				m[i].a = 2;
				cnt[2]++;
				ans += b;
				if (a >= c)
					m[i].d = b - a;
				else
					m[i].d = b - c;
			} else {
				m[i].a = 3;
				cnt[3]++;
				ans += c;
				if (a >= b)
					m[i].d = c - a;
				else
					m[i].d = c - b;
			}
		}
		if (cnt[1] <= n / 2 && cnt[2] <= n / 2 && cnt[3] <= n / 2) {
			printf("%lld\n", ans);
		} else {
			sort(m + 1, m + 1 + n, cmp);
			if (cnt[1] > n / 2) {
				int t = cnt[1] - n / 2;
				for (int i = 1; i <= n; i++) {
					if (m[i].a == 1) {
						t--;
						ans -= m[i].d;
					}
					if (t == 0)
						break;
				}
			} else if (cnt[2] > n / 2) {
				int t = cnt[2] - n / 2;
				for (int i = 1; i <= n; i++) {

					if (m[i].a == 2) {
						t--;
						ans -= m[i].d;
					}
					if (t == 0)
						break;
				}
			} else {
				int t = cnt[3] - n / 2;
				for (int i = 1; i <= n; i++) {
					if (m[i].a == 3) {
						t--;
						ans -= m[i].d;
					}
					if (t == 0)
						break;
				}
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}