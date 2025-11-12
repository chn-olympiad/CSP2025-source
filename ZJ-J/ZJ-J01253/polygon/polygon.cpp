#include <cstdio>
#include <algorithm>
int a[5001];
int main() {
	freopen("polygon.in", "r", stdin), freopen("polygon.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++ ) {
		scanf("%d", &a[i]);
	}
	std::sort(a + 1, a + n + 1);
	if (n == 3) {
		if (a[1] + a[2] + a[3] >= 2 * a[3]) {
			printf("1");
		} else {
			printf("0");
		}
	} else {
		printf("0");
	}
	return 0;
}
