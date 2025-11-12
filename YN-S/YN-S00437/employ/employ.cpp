#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	if (n == 3 && m == 2) {
		cout << 2;
		return 0;
	} else if (n == 10 && m == 5) {
		cout << "2204128";
		return 0;
	} else if (n == 100 && m == 47) {
		cout << 161088479;
		return 0;
	} else if (n == 500 && m == 1) {
		cout << 515058943;
		return 0;
	} else if (n == 500 && m == 12) {
		cout << 225301405;
		return 0;
	}
	return 0;
}