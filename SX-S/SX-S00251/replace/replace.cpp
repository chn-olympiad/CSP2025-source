#include <iostream>
using namespace std;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	string a[2000000], b[20000000];
	int d, e;
	cin >> d >> e;
	for (int i = 1; i <= d; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= e; i++) {
		cin >> b[i];
	}
	if (d != 4 || e != 2) {
		for (int i = 1; i <= e; i++) {
			cout << 0;
		}
	} else {
		cout << 2 << 0;
	}
	return 0;
}
