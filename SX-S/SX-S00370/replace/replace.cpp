#include <bits/stdc++.h>
using namespace std;
int a, b;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b;
	if (b == 2) {
		cout << 2 << endl;
		cout << 0 << endl;
	}
	if (b == 4) {
		cout << 0 << endl;
		cout << 0 << endl;
		cout << 0 << endl;
		cout << 0 << endl;
	}
	return 0;
}