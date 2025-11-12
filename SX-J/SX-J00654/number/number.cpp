#include <bits/stdc++.h>
using namespace std;
string s;
int x[1000006], cnt;


int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int c = s.length() ;
	for (int i = 0; i <= c; i++) {
		x[i] = 123;
		if (s[i] >= '0' && s[i] <= '9') {
			x[i] = int(s[i] - 48);
			cnt++;
		}
	}
	sort(x, x + c);
	for (int i = cnt - 1; i >= 0; i--) {
		cout << x[i];
	}
	return 0;
}
