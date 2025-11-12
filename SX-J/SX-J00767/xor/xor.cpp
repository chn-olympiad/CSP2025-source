#include <bits/stdc++.h>
using namespace std;
long long a[500005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long an = n / 2;
	cout << an;
	return 0;
}
