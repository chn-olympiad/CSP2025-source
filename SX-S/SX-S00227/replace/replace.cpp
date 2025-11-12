#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, m, l[100] = {}, k;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> l[i];
		if (l[i] != 'x' || l[i] != 'z') {
			k = k + 1;
		}
	}
	cout << k - 2 <<"0";
	return 0;
}
