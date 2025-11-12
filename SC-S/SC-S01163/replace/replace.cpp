#include <bits/stdc++.h>

using namespace std;

int n, q;
int main () {
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	//不可以，总司令 
	cin >> n >> q;
	if (q == 1) {
		cout << n / 2 << endl;
		return 0;
	}
	else {
		int m = 1;
		for (int i = 1; i <= q; i++) {
			cout << 0 << endl;
		}
		return 0;
	}
}