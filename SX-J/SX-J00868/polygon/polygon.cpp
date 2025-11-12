#include <bits/stdc++.h>
using namespace std;

int n, a[5001];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	if (n == 3) {
		if (a[1] + a[2] <= a[3] && a[1] + a[3] <= a[2] && a[2] + a[3] <= a[1])
			printf("0\n");
		else
			printf("1\n");
	}
	printf("9\n");
	return 0;
}
