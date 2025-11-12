#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define N 100005

long long T, n, a[N], b[N], c[N], A, B, C, sum, idx, k, t[N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	scanf("%lld", &T);
	while (T--) {
		cin >> n;
		A = 0, B = 0, C = 0, idx = 0, sum = 0, k = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%lld %lld %lld", &a[i], &b[i], &c[i]);
			if (a[i] >= b[i] && a[i] >= c[i]) {
				A++;
				b[i] -= a[i], c[i] -= a[i];
			} else if (b[i] >= a[i] && b[i] >= c[i]) {
				B++;
				a[i] -= b[i], c[i] -= b[i];
			} else {
				C++;
				a[i] -= c[i], b[i] -= c[i];
			}
			sum += max(max(a[i], b[i]), c[i]);
		} 
		if (A <= n / 2 && B <= n / 2 && C <= n / 2) {
			printf("%lld\n", sum);
			continue;
		}
		if (A > n / 2) {
			k = A - n / 2;
			for (int i = 1; i <= n; i++) {
				if (b[i] <= 0 && c[i] <= 0) t[++idx] = max(b[i], c[i]);
			}
		} else if (B > n / 2) {
			k = B - n / 2;
			for (int i = 1; i <= n; i++) {
				if (a[i] <= 0 && c[i] <= 0) t[++idx] = max(a[i], c[i]);
			}
		} else {
			k = C - n / 2;
			for (int i = 1; i <= n; i++) {
				if (a[i] <= 0 && b[i] <= 0) t[++idx] = max(a[i], b[i]);
			}
		}
		sort(t + 1, t + idx + 1);
		reverse(t + 1, t + idx + 1);
		for (int i = 1; i <= k; i++) {
			sum += t[i];
		}
		printf("%lld\n", sum);
	}
	return 0;
}

