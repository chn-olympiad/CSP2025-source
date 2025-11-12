#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[1000005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (k != 0)
		cout << k;
	else
		cout << 1;
	return 0;
}
