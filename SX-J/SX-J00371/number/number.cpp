#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("num.in", "r", stdin);
	freopen("num.out", "w", stdout);
	string s;
	int cnt[20] = {};
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			cnt[s[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		while (cnt[i] != 0) {
			cout << i;
			cnt[i]--;
		}
	}
	return 0;
}
