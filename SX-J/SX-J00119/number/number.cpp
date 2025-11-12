#include <bits/stdc++.h>
using namespace std;
string a, b;
int cnt = 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	int len = a.size();
	if (len == 1) {
		cout << len;
	}
	for (int i = 0; i <= len; i++) {
		if (a[i] < '9') {
			b[++cnt] = a[i];
		}
		for (i = 0; i <= len; i++) {
			cout << a;
		}
	}
//	for (int i = 0; i <= len; i++) {
//		if (s[i] < s.size())
//			cout << s;
//	}
	return 0;
}
