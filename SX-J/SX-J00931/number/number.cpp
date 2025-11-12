#include <bits/stdc++.h>
using namespace std;
int a0[10];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int len = s.length();
	for (int i = 0; i < len; i ++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a0[s[i] - '0'] ++;
		}
	}
	for (int i = 9; i >= 0; i --) {
		for (int j = a0[i]; j > 0; j --) {
			cout << i;
		}
	}
	return 0;
}
