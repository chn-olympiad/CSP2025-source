#include <bits/stdc++.h>
using namespace std;
long long sum;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, a;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = n; j >= 2; j--) {
			sum += i * j + i * i + j * j;
		}
	}
	cout << sum % 998244453;
	return 0;
}