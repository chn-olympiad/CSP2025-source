#include <bits/stdc++.h>
using namespace std;
string s, mmax;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int l = s.size();
	if (l == 1)
		cout << s;
	else {
		for (int i = 0; i <= l; i++) {
			if (s[i] >= '1' && s[i] <= '9' && s[i] > mmax) {
				mmax = s[i];
			}
		}
	}
	return 0;
}