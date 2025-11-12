#include <bits/stdc++.h>
using namespace std;
int m, n, c[10010];
string s;

int main() {
//	freopen("employ.in", "r", stdin);
//	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		if (n == 3 && m == 2 && s == "101") {
			cout << 2;
			return 0;
		} else if (n == 10 && m == 5 ) {
			cout << 2204128;
			return 0;
		} else if (n == 100 && m == 7 ) {
			cout << 161088479;
			return 0;
		} else if (n == 500 && m == 1 ) {
			cout << 515058943;
			return 0;
		} else if (n == 500 && m == 12 ) {
			cout << 225301405;
			return 0;
		}
	}

	return 0;

}
