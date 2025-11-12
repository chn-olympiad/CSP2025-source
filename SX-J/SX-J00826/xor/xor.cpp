#include <bits/stdc++.h>
using namespace std;
long long a[100000 + 10];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (a[m]) {
		cout << "-1";
	}
	return 0;
}
