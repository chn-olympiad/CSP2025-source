#include <bits/stdc++.h>
using namespace std;
int n, k, a[500010], h, j = 1, ans, lc;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		h = a[i];
		while (a[i] == k && i <= j - 1) {
			ans++;
			i++;
			h = a[i];
		}
		if (j == i)
			j++;
		while (j < n && h != k) {
			j++;
			h ^= a[j];
		}
		if (h == k) {
			lc = j;
			ans++;
		}
		if (j > n && lc < j) {
			for (int l = i + 1; l <= n; l++) {
				if (a[l] == k)
					ans++;
			}
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}
