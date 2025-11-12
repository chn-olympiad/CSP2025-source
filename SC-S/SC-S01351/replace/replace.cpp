#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int n, m, ans;
vector<int> f1[N];
string s1[N], s2[N];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
		f1[i].push_back(-1), f1[i].push_back(-1);
		for (int r = 1, l = -1; r < (int)s1[i].size(); r++) {
			if (l != -1 && s1[i][l + 1] != s1[i][r])
				l = f1[i][l];
			if (s1[i][l + 1] == s1[i][r])
				l++;
			f1[i].push_back(l);
		}
	}
	for (int i = 1; i <= m; i++) {
		string t1, t2;
		ans = 0;
		cin >> t1 >> t2;
		if (t1.size() != t2.size())
			puts("0");
		else {
			int l = -1, r = (int)t2.size();
			for (; l < (int)t1.size(); l++)
				if (t1[l + 1] != t2[l + 1]) {
					l++;
					break;
				}
			for (; r >= 0; r--)
				if (t1[r - 1] != t2[r - 1]) {
					r--;
					break;
				}
			for (int j = 1; j <= n; j++) {
				if (s1[j].size() > t1.size())
					continue;
				if ((int)s1[j].size() < r - l + 1)
					continue;
				for (int k = 0, ll = -1; k < (int)t1.size(); k++) {
					if (ll != -1 && t1[k] != s1[j][ll + 1])
						ll = f1[j][ll];
					if (t1[k] == s1[j][ll + 1])
						ll++;
					if (ll == (int)s1[j].size() - 1) {
						int zb = k - (int)s1[j].size() + 1;
						bool flag = 1;
						for (int t = min(l, zb); t <= max(r, k); t++) {
							if (zb <= t && t <= k) {
								if (s2[j][t - zb] != t2[t]) {
									flag = 0;
									break;
								}
							} else {
								if (t1[t] != t2[t]) {
									flag = 0;
									break;
								}
							}
						}
						ans += flag;
						ll = f1[j][ll];
					}
				}
			}
		}
		cout << ans << '\n';
	}
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
}