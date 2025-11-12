#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("number.in", "r", stdin);
	//freopen("number.out", "w", stdout);
	long long siz;
	string s;
	cin >> s;
	siz = size(s);
	for (int i = 0; i < siz; ++i) {
		if (s[i] >= '0' && s[i] <= '9') {
			cout << s[i];
		}
	}
	return 0;
}
