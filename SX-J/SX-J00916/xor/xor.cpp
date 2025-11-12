#include <bits/stdc++.h>
using namespace std;
int a[1000];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (k == 0 && a[i] == 1) {
			ans++;
		}
	}
	cout << 1;
	return 0;
}