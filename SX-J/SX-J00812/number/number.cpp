#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a;
	cin >> a;
	int x = 0;
	if (a.size() == 1) {
		cout << a;
		return 0;
	}
	for (int i = 0; i <= a.size() - 1; i++) {
		for (int j = i; j <= a.size(); j++) {
			if (a[i] > x) {
				x *= 10;
				x += a[i];
			}
		}

	}
	cout << x;
	return 0;
}
