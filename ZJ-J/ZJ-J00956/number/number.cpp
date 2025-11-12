#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, l, r) for (int i = l; i <= r; i ++)
const int N= 1e6+10;
int cnt[10];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int n = s.size();
	s = " " + s;
	rep(i, 1, n) {
		if ('0' <= s[i] && s[i] <= '9') {
			cnt[s[i]-'0'] ++;
		}
	}
	bool flag = 1;
	rep(i, 1, 9) if (cnt[i]) flag = 0;
	if (flag) return cout << 0, 0;
	for (int i = 9; i >= 0; i --) {
		while (cnt[i]) {
			cnt[i] --;
			cout << (char)(i+'0');
		}
	}
	return 0;
}
