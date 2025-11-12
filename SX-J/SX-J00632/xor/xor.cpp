#include <bits/stdc++.h>
int a[1001], b[1001], c[1001], k, n;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	b[1] = a[1];
	for (int i = 2; i <= n; i++)
		b[i] = b[i - 1] ^ a[i];

}