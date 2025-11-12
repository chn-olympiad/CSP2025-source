#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int num;
	cin >> num;
	if (num = num) {
		cout << num;
	} else {
		int a, s;
		a = num % 10;
		s = num / 10;
		if (a > s) {
			cout << s << a;
		} else {
			cout << a << s;
		}
	}
	return 0;
}
