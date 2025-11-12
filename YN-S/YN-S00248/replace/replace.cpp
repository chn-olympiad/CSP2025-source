#include <bits/stdc++.h>
using namespace std;
long long n, q, dp[5000005];
string s[200005][2], s1, s2;
vector<int> pre[200005][2];

void kmp(vector<int> &pre, vector<int> &f, string &s1, string &s2, bool is_self) {
	f.resize(s2.length(), 0);
	int len = f.size();
	for (int i = is_self ? 2 : 1, p = 0; i < len; ++i) {
		while (p != 0 && s1[p + 1] != s2[i])
			p = pre[p];
		if (s1[p + 1] == s2[i])
			++p;
		f[i] = p;
	}
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cout.tie(nullptr), cin.tie(nullptr);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i][0] >> s[i][1];
		s[i][0] = "#" + s[i][0];
		s[i][1] = "#" + s[i][1];
		kmp(pre[i][0], pre[i][0], s[i][0], s[i][0], true);
		kmp(pre[i][1], pre[i][1], s[i][1], s[i][1], true);
	}
	while (q--) {
		cin >> s1 >> s2;
		s1 = "#" + s1;
		s2 = "#" + s2;

		int len = s1.length();
		vector<int> f[len][2];
		for (int i = 1; i <= n; ++i) {

			kmp(pre[i][0], f[i][0], s[i][0], s1, false);
			kmp(pre[i][1], f[i][1], s[i][1], s2, false);
		}
		for (int i = 0; i < len; ++i)
			dp[i] = 0;
		dp[0] = 1;
		for (int i = 1; i < len; ++i) {
			if (s1[i] != s2[i])
				break;
			dp[i] = 1;
		}
		for (int i = 2; i < len; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (f[j][0][i] != pre[j][0].size() - 1)
					continue;
				if (f[j][1][i] != pre[j][1].size() - 1)
					continue;
				//cerr << q << ' ' << i << ' ' << j << ' ' << f[j][0][i] << endl;
				dp[i] += dp[i - f[j][0][i]];
			}
		}
		for (int i = 1; i < len; ++i) {
			if (s1[i] == s2[i])
				dp[i] += dp[i - 1];
		}
		cout << dp[len - 1] << '\n';
	}
	return 0;
}