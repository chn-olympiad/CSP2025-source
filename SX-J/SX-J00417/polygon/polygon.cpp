#include <bits/stdc++.h>
using namespace std;
int n, a[5005], s = 0;

int main() {
	cin >> n;
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s += a[i];
	}
	cout << s;
	return 0;
}
