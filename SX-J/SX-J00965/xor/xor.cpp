#include <bits/stdc++.h>
using namespace std;
int a[500005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, ans = 0, num;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	num = a[1];
	for (int i = 2; i <= n; i++) {
		num = num xor a[i];
		if (num == k) {
			num = a[i];
			ans++;
		}
	}
	cout << ans;
	return 0;
}
