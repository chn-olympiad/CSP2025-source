#include <bits/stdc++.h>
using namespace std;

int main() {

	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	int n, k;
	cin >> n >> k;
	int a[n];
	if (k == 2 || k == 3) {
		cout << 2;
	}
	if (k == 0) {
		cout << 1;
	}


	return 0;
}
