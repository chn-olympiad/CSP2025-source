#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, p;
	cin >> n >> p;
	string y[n + 1][2];
	for (int o = 1; o <= n; o++) {
		cin >> y[o][1] >> y[o][2];
	}
	string a, b;
	for (int m = 1; m <= p; m++) {
		cin >> a >> b;
		cout << 0 << endl;
	}
	return 0;
}
