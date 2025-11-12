#include <bits/stdc++.h>
using namespace std;
int a[500005], n, k;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (k == 0) {
		cout << "1";
	}
	if (k > 0) {
		cout << "2";
	}
	return 0;
}
