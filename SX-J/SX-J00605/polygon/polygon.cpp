#include <bits/stdc++.h>
using namespace std;
int n, a[5006];
long long cnt;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int t = n - 3;
	cout << (pow(3, t) + 1);
	return 0;
}
