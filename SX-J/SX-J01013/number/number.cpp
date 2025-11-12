#include <bits/stdc++.h>
using namespace std;
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int c = s.size(), m = 0, d = 0;
	if (c == 1)
		cout << s;
	else {
		for (int j = 0; j < c; j++) {
			if (s[j] == '1' or s[j] == '2' or s[j] == '3' or s[j] == '4' or s[j] == '5' or s[j] == '6' or s[j] == '7'
			        or s[j] == '8' or s[j] == '9') {
				cout << s[j];
				//d = s[j];
				//	d =
				//	m = max(m, d);
			}
		}
		//	cout << m ;
		//	m = 0;
		//	d = 0;
	}
	return 0;
}