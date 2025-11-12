#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	int sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		n % 998;
		n % 244;
		n % 353;
		sum += n;
	}
	cout << n;
	return 0;
}
