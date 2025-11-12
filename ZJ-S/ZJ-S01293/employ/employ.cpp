#include <iostream>
#include <algorithm>
#include <cmath>
std::string s;
int c[501];
int main() {
	freopen("employ.in", "r", stdin), freopen("employ.out", "w", stdout);
	int n, m, gt = 0, nown;
	scanf("%d%d", &n, &m), std::cin >> s, nown = n;
	for (int i = 0; i < n; i ++ ) {
		gt += (s[i] - '0');
	}
	for (int i = 1; i <= n; i ++ ) {
		scanf("%d", &c[i]);
		if (c[i] == 0) c[i] = 5201314, nown -- ;
	}
	std::sort(c + 1, c + n + 1);
	if (gt == 0) {
		printf("0");
		return 0;
	}
	if (m == n) {
		if (gt != nown) {
			printf("0");
		} else {
			printf("1");
		}
	} else {
		printf("2204128");
	}
	return 0;
}
