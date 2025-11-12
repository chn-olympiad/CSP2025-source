//2025csp-s mzyz ÀîÄ­è°
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 6;
int n, q, id[N][2];
string s[N][2];
map<int, vector<int> >mp;

int main() {
//	freopen("replace4.in", "r", stdin);
//	freopen("T3.out", "w", stdout);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i][0] >> s[i][1];
		id[i][0] = id[i][1] = -1;
		for (int u = 0; u < s[i][0].size(); u++) {
			if (s[i][0][u] != 'a' && s[i][0][u] != 'b' && s[i][1][u] != 'a' && s[i][1][u] != 'b') {
				while (q--) {
					cout << "0\n";
				}
				return 0;
			}
			if (s[i][0][u] == 'b') {
				if (id[i][0] != -1) {
					while (q--) {
						cout << "0\n";
					}
					return 0;
				}
				id[i][0] = u;
			}
			if (s[i][1][u] == 'b') {
				if (id[i][1] != -1) {
					while (q--) {
						cout << "0\n";
					}
					return 0;
				}
				id[i][1] = u;
			}
		}
		if (id[i][0] == -1 || id[i][1] == -1) {
			while (q--) {
				cout << "0\n";
			}
			return 0;
		}
		mp[id[i][0] - id[i][1]].push_back(i);
	}
	while (q--) {
		string a, b;
		cin >> a >> b;
		bool bol = 0;
		int ida = -1, idb = -1;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != 'a' && a[i] != 'b') {
				bol = 1;
				break;
			}
			if (a[i] == 'b') {
				if (ida != -1) {
					bol = 1;
					break;
				}
				ida = i;
			}
		}
		if (bol || ida == -1) {
			cout << "0\n";
			continue;
		}
		for (int i = 0; i < b.size(); i++) {
			if (b[i] != 'a' && b[i] != 'b') {
				bol = 1;
				break;
			}
			if (b[i] == 'b') {
				if (idb != -1) {
					bol = 1;
					break;
				}
				idb = i;
			}
		}
		if (bol || idb == -1) {
			cout << "0\n";
			continue;
		}
		int ans = 0;
		vector<int>v = mp[ida - idb];
		for (int i = 0; i < v.size(); i++) {
			int u = v[i];
			if (id[u][0] > ida || s[u][0].size() - id[u][0] > a.size() - ida) {
				continue;
			}
			if (id[u][1] > idb || s[u][1].size() - id[u][1] > b.size() - idb) {
				continue;
			}
			ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}