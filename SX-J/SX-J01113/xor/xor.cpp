#include <bits/stdc++.h>
using namespace std;
int a[500010];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, maxn = LLONG_MIN;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int q;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (a[i]^a[j] == k) {
				q = j - i;
			}
			maxn = max(maxn, q);
		}
	}
	cout << maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}