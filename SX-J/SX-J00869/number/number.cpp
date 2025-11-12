#include <bits/stdc++.h>
using namespace std;
string a;
long long b[2060000], c, s, l;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	getline(cin, a);
	for (int i = 0; i < a.size(); i++) {
		if (a[i] - '0' == 1 || a[i] - '0' == 2 || a[i] - '0' == 3) {
			b[i] = a[i] - '0';
		} else if (a[i] - '0' == 4 || a[i] - '0' == 5 || a[i] - '0' == 6) {
			b[i] = a[i] - '0';
		} else if (a[i] - '0' == 7 || a[i] - '0' == 8 || a[i] - '0' == 9) {
			b[i] = a[i] - '0';
		} else if (a[i] - '0' == 0) {
			l++;
		}
	}
	sort(b, b + a.size(), cmp);
	for (int i = 0; i < a.size() ; i++) {
		if (b[i] != 0) {
			c = c * 10 + b[i];
			s++;
		}
	}
	cout << c;
	for (int i = 1; i <= l; i++) {
		cout << 0;
	}
	return 0;
}
