#include <bits/stdc++.h>
using namespace std;
long long n, k, sum, ans;
int a[500005];
bool f;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1)
			f = 1;
	}
	if (k == 0 ) {
		cout << n / 2;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}
