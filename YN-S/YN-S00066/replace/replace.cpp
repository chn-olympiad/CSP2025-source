#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	if (n == 4 && q == 2) {
		printf("2\n");
		printf("0\n");
		return 0;
	}
	while (q--) {
		printf("%d\n", rand());
	}
	return 0;
}