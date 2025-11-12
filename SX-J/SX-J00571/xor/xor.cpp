#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, a[10005];
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a, a + n + 1, greater<int>());
	cout << a[1];
	return 0;
}
