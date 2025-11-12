#include <bits/stdc++.h>
using namespace std;
string  s;
char mmax;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int l = s.size();
	for (int i = 0; i <= l; i++) {
		if (s[i] >= '0' && s[i] <= '9' ) {
		}
		for (int i = 0; i <= l; i++) {
			while (s[i] > mmax) {
				mmax = s[i];
				cout << mmax;
			}
		}
	}
	return 0;
}