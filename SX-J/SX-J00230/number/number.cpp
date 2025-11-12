#include <bits/stdc++.h>
using namespace std;
string s;
int tong[15];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' and s[i] <= '9') {
			tong[s[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		while (tong[i] != 0) {
			cout << i;
			tong[i]--;
		}
	}
	return 0;
}
