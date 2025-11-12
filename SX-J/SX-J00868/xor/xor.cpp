#include <bits/stdc++.h>
using namespace std;

int n, a[500002], k, ans = 0, x = 1;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		if ((a[i] ^ a[i + 1]) == k)
			ans++;
	printf("%d\n", ans);
	return 0;
}
