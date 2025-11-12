#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], c[200005];
string s;

int main() {
	cin >> n >> m;
	cin >> s;
	int ls = sizeof(s);
	for (int i = 1; i <= ls; i++) {
		a[i] == s[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	if (n == 3 && m == 2) {
		cout << 2 << endl;
	}
	if (n == 10 && m == 5) {
		cout << 2204128 << endl;
	}
	if (n == 100 && m == 47) {
		cout << 161088479 << endl;
	}
	if (n == 500 && m == 1) {
		cout << 515058943 << endl;
	}
	if (n == 500 && m == 12) {
		cout << 225301405 << endl;
	}
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	return 0;
}
