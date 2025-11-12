#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdin);
	long s;
	cin >> s;
	int a = s % 10 ;
	int b = s / 10;
	if (s % 10 == s) {
		cout << s;
	}
	if (s % 100 == s && s % 10 != s) {
		if (s % 10 < s / 10 || s % 10 == s / 10) {
			cout << s;
		}
		if (s % 10 > s / 10) {
			s = a * 10 + b;
			cout << s;
		}
	}



	return 0;
}

