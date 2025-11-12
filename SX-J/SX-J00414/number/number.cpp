#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int s;
	cin >> s;
	string a;
	cin >> a;
	for (int i = 1; i <= 9; i++) {
		if (s == a[i]) {
			cout << a[i];
		}
	}
	cout << s;
	return 0;
}