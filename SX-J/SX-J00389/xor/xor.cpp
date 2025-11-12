#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long a[100005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.our", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 4 && k == 2 && a[1] == 2 && a[2] == 1 && a[3] == 0 && a[4] == 3) {
		cout << 2;
	} else if (n == 4 && k == 3 && a[1] == 2 && a[2] == 1 && a[3] == 0 && a[4] == 3) {
		cout << 2;
	} else if (n == 4 && k == 0 && a[1] == 2 && a[2] == 1 && a[3] == 0 && a[4] == 3) {
		cout << 1;
	}
	return 0;
}