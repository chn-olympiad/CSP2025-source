#include <bits/stdc++.h>
using namespace std;
string s;
int t[20];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	long long len = s.size() - 1;
	for (int i = 0; i <= len; i++) {
		if (s[i] >= '0' && s[i] <= '9')
			t[s[i] - '0']++;
	}
	if (t[1] + t[2] + t[3] + t[4] + t[5] + t[6] + t[7] + t[8] + t[9] == 0 && t[0] >= 0) {
		cout << 0;
		return 0;
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= t[i]; j++) {
			cout << i;
		}
	}
	return 0;
}
