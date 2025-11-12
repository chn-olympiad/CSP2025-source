#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, p;
	cin >> n >> p;
	string a;
	cin >> a;
	int b, lj = 0, bzd = 1;
	for (int o = 1; o <= n; o++) {
		cin >> b;
		bzd *= b;
		if (b == 0) {
			lj++;
		}
	}
	if (p == 1) {
		cout << n - lj << endl;
		return 0;
	}
	cout << bzd << endl;
	return 0;
}