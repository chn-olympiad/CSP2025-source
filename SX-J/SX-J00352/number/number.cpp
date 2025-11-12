#include <bits/stdc++.h>
using namespace std;
string s, c;
int a[1000005], b[13];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i <= s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			c[i] = s[i];
			if (c[i] < c[i + 1]) {
				swap(c[i], c[i + 1]);
			}
		}
	}
	for (int j = 0; j <= s.size(); j++) {
		cout << c[j];
	}
	return 0;
}