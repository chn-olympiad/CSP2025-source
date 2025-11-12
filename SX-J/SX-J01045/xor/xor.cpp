#include <bits/stdc++.h>
using namespace std;

int n, k, a[500010], ans;
bool f = true;

int main() {
	int i;
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 0)
			f = false;
	}
	if (k) {
		if (f)
			printf("%d", n);
		else {
			for (i = 0; i < n; i++) {
				if (a[i] == 1)
					ans++;
			}
			printf("%d", ans);
		}
	} else {
		if (f)
			printf("%d", n / 2);
		else {
			for (i = 0; i < n; i++) {
				if (i == n - 1 && i)
					break;
				if (a[i] == 1 && a[i + 1] == 1) {
					i++;
					ans++;
				}
				if (i == 0)
					ans++;
			}
			printf("%d", ans);
		}
	}
	return 0;
}
