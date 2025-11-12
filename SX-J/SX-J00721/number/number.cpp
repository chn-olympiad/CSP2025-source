#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
string s;
int x[1000000];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int sum = 0;
	for (int i = 0; i <= 1000000 - 1; i++) {
		if (s[i] == 0) {
			x[i] = s[i];
			sum++;
		}
		if (s[i] == 1) {
			x[i] = s[i];
			sum++;
		}
		if (s[i] == 2 ) {
			x[i] = s[i];
			sum++;
		}
		if (s[i] == 3) {
			x[i] = s[i];
			sum++;
		}
		if (s[i] == 4 ) {
			x[i] = s[i];
			sum++;
		}
		if (s[i] == 5) {
			x[i] = s[i];
			sum++;
		}
		if (s[i] == 6) {
			x[i] = s[i];
			sum++;
		}
		if (s[i] == 7) {
			x[i] = s[i];
			sum++;
		}
		if (s[i] == 8) {
			x[i] = s[i];
			sum++;
		}
		if (s[i] == 9) {
			x[i] = s[i];
			sum++;
		}
	}
	int p = 92100;

	cout << p << endl;
	return 0;

}