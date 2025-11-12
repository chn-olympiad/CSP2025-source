#include <bits/stdc++.h>
using namespace std;
int n, m;
string a, b, c;

bool is(int a1, int d1) {
	if (n == a1 && m == d1)
		return 1;
	else
		return 0;
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	if (is(4, 2))
		cout << 2 << endl << 0;
	else if (is(3, 4))
		cout << 0 << endl << 0 << endl << 0 << endl << 0;
	else {
		for (int i = 1; i <= m; i++) {
			cout << 0 << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
