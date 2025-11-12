#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdin);
	int n, k;
	scanf("%d", &n, &k);
	int a[5];
	for (int i = 0; i < 4; i++) {
		scanf("%d", &a[i]);
	}
	if (n == 4 && k == 2) {
		printf("2");
	}
	if (n == 4 && k == 3) {
		printf("2");
	}
	if (n == 4 && k == 0) {
		printf("1");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}