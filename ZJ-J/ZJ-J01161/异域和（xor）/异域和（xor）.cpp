#include<bits/stdc++.h>
using namespace std;
int main () {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	int a[50000];
	cin >> a[n];
	if (k == 0) {
		cout << 1 << endl;
	}
	else {
		if (k == 1) {
			cout << n << endl;
		}
	}
	return 0;
}
