#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 2e5 + 5;
string s1[N][4], s2[N][4];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i][0] >> s2[i][0];
		int p = -1, p2 = s1[i][0].size();
		for (int j = 0; j < s1[i][0].size(); j++) {
			if (s1[i][0][j] == s2[i][0][j]) {
				s1[i][1] += s1[i][0][j];
				p = j;
				continue;
			}
			break;
		}
		for (int j = s1[i][0].size() - 1; j >= 0; j--) {
			if (s1[i][0][j] == s2[i][0][j]) {
				s1[i][3] = s1[i][0][j] + s1[i][3];
				p2 = j;
				continue;
			}
			break;
		}
		for (int j = p + 1; j < p2; j++) {
			if (s1[i][0][j] != s2[i][0][j]) {
				s1[i][2] += s1[i][0][j];
				s2[i][2] += s2[i][0][j];
				continue;
			}
			break;
		}
	}
	while (q--) {
		string t1[4] = {""}, t2[4] = {""};
		cin >> t1[0] >> t2[0];
		int p = -1, ans = 0, p2 = t1[0].size();
		for (int j = 0; j < t1[0].size(); j++) {
			if (t1[0][j] == t2[0][j]) {
				t1[1] += t1[0][j];
				p = j;
				continue;
			}
			break;
		}
		for (int j = t1[0].size() - 1; j >= 0; j--) {
			if (t1[0][j] == t2[0][j]) {
				t1[3] = t1[0][j] + t1[3];
				p2 = j;
				continue;
			}
			break;
		}
		for (int j = p + 1; j < p2; j++) {
			if (t1[0][j] != t2[0][j]) {
				t1[2] += t1[0][j];
				t2[2] += t2[0][j];
				continue;
			}
			break;
		}
		for (int i = 1; i <= n; i++) {
			int flag = 1;
			if (t1[2] != s1[i][2] || t2[2] != s2[i][2]) flag = 0;
			if (t1[1].empty() && !s1[i][1].empty()) flag = 0;
			else if (t1[1].empty());
			else for (int j = 0; !s1[i][1].empty() && j < s1[i][1].size(); j++) {
				if (t1[1][t1[1].size() - 1 - j] != s1[i][1][s1[i][1].size() - 1 - j]) flag = 0;
			}
			if (t1[3].empty() && !s1[i][3].empty()) flag = 0;
			else if (t1[3].empty());
			else for (int j = 0; !s1[i][3].empty() && j < s1[i][3].size(); j++) {
				if (t1[3][j] != s1[i][3][j]) flag = 0;
			}
			ans += flag;
		}
		cout << ans << '\n';
	}
	return 0;
}