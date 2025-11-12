#include <bits/stdc++.h>
using namespace std;
char s;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	cin >> s;
	int n;
	cin >> n;
	int a, b;
	cin >> a >> b;
	if (n > a) {
		cout << n;
	} else {
		cout << a;
	}
	if (n > b) {
		cout << n;
	} else {
		cout << b;

	}

	if (a > b) {
		cout << a;

	} else {
		cout << b;
	}
	int q, w, e, r, t;
	int o;
	cin >> o ;
	cin >> q >> w >> e >> r >> t;
	for (int i = 1; i <= o; i++) {
		cout << a << b << n;
	}
fclose(stdin);
fclose(stdout);

	return 0;
}
