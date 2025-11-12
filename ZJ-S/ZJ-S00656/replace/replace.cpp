#include <bits/stdc++.h>
using namespace std;
string a[200010][2], b[200010][2];
vector <pair <int, int> > v[400020];
int nowl, nowr;
int Check(string s) {
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != 'a' && s[i] != 'b') return 0;
		cnt += s[i] == 'b';
	}
	return cnt == 1;
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	int fl = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][0] >> a[i][1];
		if (!Check(a[i][0]) || !Check(a[i][1])) fl = 0;
	}
	for (int i = 1; i <= q; i++) {
		cin >> b[i][0] >> b[i][1];
		if (!Check(b[i][0]) || !Check(b[i][1])) fl = 0;
	}
	if (fl) {
		for (int i = 1; i <= n; i++) {
			int l, r;
			for (int j = 0; j < a[i][0].size(); j++)
				if (a[i][0][j] == 'b') l = j;
			for (int j = 0; j < a[i][1].size(); j++)
				if (a[i][1][j] == 'b') r = j;
			v[r - l + 200010].push_back({l - 1, a[i][0].size() - l});
		}
		for (int i = 1; i <= q; i++) {
			int l, r;
			for (int j = 0; j < b[i][0].size(); j++)
				if (b[i][0][j] == 'b') l = j;
			for (int j = 0; j < b[i][1].size(); j++)
				if (b[i][1][j] == 'b') r = j;
			nowl = l - 1, nowr = b[i][0].size() - l;
			int now = r - l + 200010;
//			sort(v[now].begin(), v[now].end(), cmp);
			int ccnt = 0;
			for (int kk = 0; kk < v[now].size(); kk++) {
				if (v[now][kk].first <= nowl && v[now][kk].second <= nowr) ccnt++;
			}
			printf("%d\n", ccnt);
		}
	}
	for (int i = 1; i <= q; i++) {
		long long ans = 0;
		int L = b[i][0].size();
		for (int l = 0; l < L; l++) {
			for (int j = 1; j <= n; j++) {
				if (a[j][0].size() + l - 1 >= L) continue;
				int flg = 1;
				for (int k = 0; k < a[j][0].size(); k++)
					if (b[i][0][l + k] != a[j][0][k]) {
						flg = 0; break;
					}
				if (!flg) continue;
				for (int k = 0; k < a[j][0].size(); k++)
					if (b[i][1][l + k] != a[j][1][k]) {
						flg = 0; break;
					}
				if (!flg) continue;
				for (int k = 0; k < b[i][0].size(); k++) {
					if (k < l || k > l + a[j][0].size() - 1) {
						if (b[i][0][k] != b[i][1][k]) {
							flg = 0; break;
						}
					}
				}
				if (!flg) continue;
//				cout << l << ' ' << j << '\n';
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}