#include<bits/stdc++.h>
using namespace std;

int a[500001], f[500010], n, k;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	a[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	memset(f, 0, sizeof(f));
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= n - i; j++) {
			f[j] += f[j + i];
			if (a[j] == k)
				f[j] = max(f[j], 1);
			a[j] = a[j] ^ a[j + 1];
		}
	}
	printf("%d\n", f[1]);
	return 0;
}
