#include <bits/stdc++.h>
using namespace std;
string s, x;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int y = 0;
	int a = s.size();
	for (int i = 0; i < a; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			x[y] = s[i];
			y++;
		}
	}
	int c = y, d;
	for (int j = 0; j < y ; j++) {
		for (int i = 0; i < y; i++) {
			if (x[d] < x[i]) {
				d = i;
			}
		}
		cout << x[d];
		x[d] = '-';
		c--;
	}
	return 0;
}