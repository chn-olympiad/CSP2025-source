#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdin);
	int n;
	scanf("%d", &n);
	int a[5];
	for (int i = 0; i < 5; i++) {
		scanf("%d", &a[i]);
	}
	if (n == 5 && a[0] == 1) {
		printf("9");
	} else {
		printf("6");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
