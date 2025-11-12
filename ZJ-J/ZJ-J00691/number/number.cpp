#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define FOR(i, l, r, x) for (int i = l; i <= r; i = x)
#define DEFOR(i, l, r, x) for (int i = l; i >= r; i = x)
using namespace std;
int mp[15] = {};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	FOR(i, 0, s.size() - 1, ++i) {
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
			mp[s[i] - '0']++;
		}
	}
	DEFOR(i, 9, 0, --i) {
		FOR(j, 1, mp[i], ++j) {
			cout << i;
		}
	}
	cout << endl;
	return 0;
}