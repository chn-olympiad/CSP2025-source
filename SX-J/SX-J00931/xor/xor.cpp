#include <bits/stdc++.h>
using namespace std;

int a0[200001] = {1};

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	bool tmp1 = 1;
	for (int i = 1; i <= n; i ++) {
		cin >> a0[i];
		if (a0[i] != a0[i - 1]) {
			tmp1 = 0;
		}
	}
	if (tmp1) {
		cout << n;
	} else {
		;
	}
	return 0;
}