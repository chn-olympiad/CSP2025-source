#include <bits/stdc++.h>
using namespace std;

long long cnt[10];
string s;

int main() {
	freopen("number.in", "r",stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] <= '9' && s[i] >= '0') {
			cnt[s[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		if (cnt[i] == 0) continue;
		while (cnt[i]--) {
			cout << i;	
		}
	}
	return 0;
}
