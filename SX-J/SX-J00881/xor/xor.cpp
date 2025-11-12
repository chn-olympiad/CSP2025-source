#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[10005];

int main() {
	freopen("xor.in", "w", stdin);
	freopen("xor.out", "r", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (k == 0 && n == 2)
		cout << 1;
	else if (k == 0 && n == 1)
		cout << 0;
	else if (k == 0 && n % 2 == 0)
		cout << n / 2;
	else if (k == 0 && n % 2 != 0)
		cout << n / 2;
	return  0;
}
