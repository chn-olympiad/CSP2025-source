#include <bits/stdc++.h>
using namespace std;
int s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int a = s / 1 % 10;
	int b = s / 10 % 10;

	if (s <= 10) {
		cout << s;
	} else if (s > 10 && s < 100 && a > b) {
		cout << a << b;
	} else if (s > 10 && s < 100 && b > a) {
		cout << b << a;
	}
	return 0;
}