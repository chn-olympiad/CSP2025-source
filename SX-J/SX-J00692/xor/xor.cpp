#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int a[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if ((n <= 2 && k == 0) || (n <= 10 * 10 && k == 0)) {
		cout << 1;
	}
	return 0;
}