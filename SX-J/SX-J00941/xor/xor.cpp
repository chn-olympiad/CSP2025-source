#include <bits/stdc++.h>
using namespace std;
int a[100001];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, m, ans = 0, sum = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++) {
			int k;
			for (k = j + 1, sum = a[j]; k <= i; k++)
				sum ^= a[k];
			if (sum == m) {
				ans++;
				j = i++;
			}
		}
	cout << ans;
	return 0;
}