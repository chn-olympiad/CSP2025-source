#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
int n, q, l[N], r[N], d[N], pos1[N], pos2[N];
string s1[N], s2[N], t1, t2;
vector <pair<int, int> > p1[N], p2[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
		l[i] = -1;
		for (int j = 0; j < s1[i].size(); j++) {
			if (s1[i][j] != s2[i][j] && l[i] == -1) l[i] = j;
			if (s1[i][j] != s2[i][j]) r[i] = j;
		}
	}
	if (q == 1) {
		cin >> t1 >> t2;
		if (t1.size() != t2.size()) {
			cout << 0;
		}
		else {
			int ll = -1, rr = -1, ans = 0;
			for (int i = 0; i < t1.size(); i++) {
				if (t1[i] != t2[i] && ll == -1) ll = i;
				if (t1[i] != t2[i]) rr = i;
			}
			for (int i = 1; i <= n; i++) {
				if (rr - ll == r[i] - l[i] && l[i] != -1) {
					int L = ll - l[i], R = rr + s1[i].size() - r[i] - 1;
					if (L < 0 || R >= t1.size()) continue;
					bool f = 0;
					for (int j = L; j <= R; j++) {
						if (t1[j] != s1[i][j - L]) f = 1;
						if (t2[j] != s2[i][j - L]) f = 1;
					}
					if (!f) ans++;
				}
			}
			cout << ans;
		}
	}
	else if (n <= 1000 && q <= 1000) {
		while (q--) {
			cin >> t1 >> t2;
			if (t1.size() != t2.size()) {
				cout << "0\n";
				continue;
			}
			int ll = -1, rr = -1, ans = 0;
			for (int i = 0; i < t1.size(); i++) {
				if (t1[i] != t2[i] && ll == -1) ll = i;
				if (t1[i] != t2[i]) rr = i;
			}
			for (int i = 1; i <= n; i++) {
				if (rr - ll == r[i] - l[i] && l[i] != -1) {
					int L = ll - l[i], R = rr + s1[i].size() - r[i] - 1;
					if (L < 0 || R >= t1.size()) continue;
					bool f = 0;
					for (int j = L; j <= R; j++) {
						if (t1[j] != s1[i][j - L]) f = 1;
						if (t2[j] != s2[i][j - L]) f = 1;
					}
					if (!f) ans++;
				}
			}
			cout << ans << '\n';
		}
	}
	else {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < s1[i].size(); j++) {
				if (s1[i][j] == 'b') pos1[i] = j;
				if (s2[i][j] == 'b') pos2[i] = j;
			}
			d[i] = pos1[i] - pos2[i];
			if (d[i] > 0) p1[d[i]].push_back(make_pair(pos2[i], s1[i].size() - 1 - pos1[i]));
			if (d[i] < 0) p2[-d[i]].push_back(make_pair(pos1[i], s1[i].size() - 1 - pos2[i]));
		}
		while (q--) {
			cin >> t1 >> t2;
			if (t1.size() != t2.size()) {
				cout << "0\n";
				continue;
			}
			int po1, po2, dd;
			for (int i = 0; i < t1.size(); i++) {
				if (t1[i] == 'b') po1 = i;
				if (t2[i] == 'b') po2 = i;
			}
			dd = po1 - po2;
			int ans = 0;
			if (dd > 0) {
				for (int i = 0; i < p1[dd].size(); i++) {
					if (po2 >= p1[dd][i].first && t1.size() - 1 - po1 >= p1[dd][i].second) ans++;
				}
			}
			if (dd < 0) {
				for (int i = 0; i < p2[-dd].size(); i++) {
					if (po1 >= p2[-dd][i].first && t1.size() - 1 - po2 >= p2[-dd][i].second) ans++;
				}
			}
			cout << ans << '\n';
		}
	}
	
	return 0;
}
