#include <bits/stdc++.h>
using namespace std;
string s;
int c;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int a = size(s);
	int b = a - 1;
	for (int i = 0; i <= b; i++) {
		if (s[i] >= 0) {
			c = s[i];
		}
	}
	cout << c;
	return 0;
}

