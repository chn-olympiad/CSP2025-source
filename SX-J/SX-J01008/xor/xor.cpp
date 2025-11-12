#include <bits/stdc++.h>
using namespace std;
int a[500005], b[500005], bk = 1, n, k, ans;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		for (int j = bk; j <= i; j++) {
			b[j] ^= a[i];
			if (b[j] == k) {

				ans++, bk = i + 1;

				break;
			}

		}
	}
	cout << ans;
	return 0;
}