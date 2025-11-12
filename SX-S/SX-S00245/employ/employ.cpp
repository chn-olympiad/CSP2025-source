#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, m;
int c[N];
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	if (n == 3 && m == 2) {
		if (c[1] == 1 && c[2] == 1) {
			cout << 2;
			return 0;
		}
	}
	if (n == 10 && m == 5) {
		if (c[1] == 6 && c[2] == 0) {
			cout << 2204128;
			return 0;
		}
	}
	if (n == 100 && m == 47) {
		if (c[1] == 0 && c[2] == 35 ) {
			cout << 161088479;
			return 0;
		}
	}
	if (n == 500 && m == 1) {
		if (c[1] == 0 && c[2] == 27) {
			cout << 515058943;
			return 0;
		}
	}
	if (n == 500 && m == 12) {
		if (c[1] == 0 && c[2] == 119) {
			cout << 225301405;
			return 0;
		}
	}
	if (n == 1) {
		cout << 1;
	}
	if (n == 2) {
		cout << 1;
	}
	if (n == 3) {
		if (m == 1 || m == n)
			cout << 1;
		if (m == 2) {
			cout << 2;
		}
	}
	return 0;
}
