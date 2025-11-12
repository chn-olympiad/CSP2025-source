#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define i128 _int128_t
#define endl "\n"
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1e6+100;
const int MaxN = 1e9;
int t[10];

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	memset(t, 0, sizeof(t));
	for (int i = 0; i <= s.size(); i++) {
		if (s[i] <= '9' && s[i] >= '0') {
			int it = s[i] - '0';
			t[it]++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		while (t[i]--) {
			cout << i;
		}
	}
	return 0;
}
