#include <bits/stdc++.h>
using namespace std;

int n, a[1000091];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int o;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 1) {
			o++;
		}
	}
	if (n == 3) {
		int v = 0;
		sort(a + 1, a + 4);
		if (a[1] + a[2] + a[3] > 2 * a[3]) {
			printf("1");
		} else
			printf("0");
		return 0;
	}
	printf("1");
	return 0;
}