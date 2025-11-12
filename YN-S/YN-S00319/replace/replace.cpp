#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;

pair<string, string> ser;
//map<pair<string, string>, pair<int, int> > mm;
map<pair<int, int>, int> mc;
string s1, s2;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1 >> s2;
		int si = s1.size(), b1 = -1, b2 = -1;
		for (int i = 0; i < si; i++) {
			if (s1[i] == 'b')
				b1 = i;
			if (s2[i] == 'b')
				b2 = i;
		}
		mc[ {b1, b2}]++;
	}
	for (int i = 1; i <= q; i++) {
		cin >> s1 >> s2;
		int si = s1.size(), b1, b2;
		for (int i = 0; i < si; i++) {
			if (s1[i] == 'b')
				b1 = i;
			if (s2[i] == 'b')
				b2 = i;
		}
		cout << mc[ {b1, b2}] << '\n';
	}
	return 0;
}
