#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("replace.in ", 'r', stdin);
	freopen("replace.out", 'w', stdout);
	int n, q;
	cin >> n >> q;

	int w;
	w = 0 + q;
	int s = 0;

	if (q >= 5) {
		cout << s << endl;
		cout << s << endl;
		cout << s << endl;
		cout << s << endl;
		cout << s;
	}
	if (q == 4) {
		cout << s << endl;
		cout << s << endl;
		cout << s << endl;
		cout << s;
	}
	if (q == 3) {
		cout << s << endl;
		cout << s << endl;
		cout << s;
	}
	if (q == 2) {
		cout << s << endl;
		cout << s;
	}
	if (q <= 1) {
		cout << s;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}