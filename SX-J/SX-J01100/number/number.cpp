#include <bits/stdc++.h>
using namespace std;
string a;
long long q[15];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			q[a[i] - '0']++;
		}
	}
	bool n = true;
	for (int i = 9; i >= 0; i--) {
		if (i == 0 && n == true) {
			cout << 0;
		}
		if (q[i] != 0) {
			n = false;
			for (int j = 1; j <= q[i]; j++) {
				cout << i;
			}
		}
	}
	return 0;
}
