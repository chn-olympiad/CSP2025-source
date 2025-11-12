#include <bits/stdc++.h>
#define int long long
#define fr(i, a, b) for(int i = a; i <= b; i++)
using namespace std;
int num[15];

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			num[s[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		fr(j, 1, num[i]) {
			cout << i;
		}
	}
	return 0;
}
