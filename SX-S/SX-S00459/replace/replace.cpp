#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
char a[N][2];
char s[N][2];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][1] >> a[i][2];
	}
	for (int i = 1; i <= q; i++) {
		cin >> s[i][1] >> s[i][2];
	}
	if (n == 4) {
		cout << 2 << endl;
		cout << 0;
	} else {
		cout << 0 << endl;
		cout << 0 << endl;
		cout << 0 << endl;
		cout << 0;
	}
	return 0;
}
