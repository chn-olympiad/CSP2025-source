#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define File(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
using namespace std;
string s;
int cnt[10];
signed main() {
	File("number");
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i ++) {
		if (isdigit(s[i])) {
			cnt[s[i] - '0'] ++;
		}
	}
	for (int i = 9; i >= 0; i --) {
		while (cnt[i] > 0) {
			cout << i;
			cnt[i] --;
		}
	}
	cout << endl;
	return 0;
}
