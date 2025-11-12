#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, a[10001], s = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s += a[i];
	}
	cout << s << endl;
	return 0;
}