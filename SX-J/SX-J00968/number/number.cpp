#include <bits/stdc++.h>
using namespace std;
long long t[10000005];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	int l = 9;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			t[s[i] - '0']++;
		}
	}
	if (t[0] != 0 && t[1] == 0 && t[2] == 0 && t[3] == 0 && t[4] == 0 && t[5] == 0 && t[6] == 0 && t[7] == 0 && t[8] == 0
	        && t[9] == 0) {
		cout << 0;
		return 0;
	}
	while (l != -1) {
		if (t[l] != 0) {
			cout << l;
			t[l]--;
		} else
			l--;
	}
	return 0;
}
