#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 5e6 + 5;
string s[N], s1[N], a[N], b[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> s[i] >> s1[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 1; i <= m; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			int l = s[i].find(a[j]);
			if (l != -1) {
				string x = "", y = "", z = "";
				for (int k = 0; k < l; k++) {
					x += s[i][k];
				}

				for (int k = 0; k < b[j].size(); k++) {
					y += b[j][k];
				}
				for (int k = l + a[j].size(); k < s[i].size(); k++) {
					z += s[i][k];
				}
				string s3 = x + y + z;
				if (s3 == s1[i])
					cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}