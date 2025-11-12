#include <bits/stdc++.h>
using namespace std;
string s;
int n, t[1000006];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' and s[i] <= '9') {
			n++;
			if (s[i] == '0') {
				t[n] = 0;
			}
			if (s[i] == '1') {
				t[n] = 1;
			}
			if (s[i] == '2') {
				t[n] = 2;
			}
			if (s[i] == '3') {
				t[n] = 3;
			}
			if (s[i] == '4') {
				t[n] = 4;
			}
			if (s[i] == '5') {
				t[n] = 5;
			}
			if (s[i] == '6') {
				t[n] = 6;
			}
			if (s[i] == '7') {
				t[n] = 7;
			}
			if (s[i] == '8') {
				t[n] = 8;
			}
			if (s[i] == '9') {
				t[n] = 9;
			}
		}
	}
	sort(t + 1, t + n + 1);
	for (int i = n; i >= 1; i--) {
		cout << t[i];
	}

	return 0;
}