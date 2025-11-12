#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e6 + 8;
string s;
int cnt[10];
string ans;
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			cnt[s[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		while (cnt[i] > 0) {
			ans += char(i + '0');
			cnt[i]--;
		}
	}
	cout << ans;
	return 0;
} 
