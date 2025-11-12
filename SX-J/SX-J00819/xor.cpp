#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	if (k == 1) {
		printf("1");
		return 0;
	}
	printf("%d", n / 2);
	return 0;
}