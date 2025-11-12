#include <bits/stdc++.h>
using namespace std;
long long a[100000 + 10];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long n;
	cin >> n;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (a[n]) {
		cout << "-1";
	}
	return 0;
}