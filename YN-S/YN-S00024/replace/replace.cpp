#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10, M = 5e6 + 10;

int n, q;
pair<string, string> s[N];
map<pair<string, string>, bool> mp;

namespace solveB {
	int ans[N];
	pair<string, string> t[N];
	vector<int> num[N];
	map<int, int> dif;
	bool cmp (pair<string, string> a, pair<string, string> b) {
		return a.first.size() < b.first.size();
	}
	void solve (void) {
		for (int i = 1; i <= q; i++)
			cin >> t[i].first >> t[i].second, num[t[i].first.size()].push_back(i);
		sort(s + 1, s + n + 1, cmp);
		for (int i = 1; i <= n; i++) {
			int p1, p2;
			for (int j = 0; j < s[i].first.size(); j++)
				if (s[i].first[j] == 'b')
					p1 = j;
			for (int j = 0; j < s[i].first.size(); j++)
				if (s[i].second[j] == 'b')
					p2 = j;
			dif[p2 - p1 + n]++;
			if (s[i].first.size() != s[i + 1].first.size()) {
				for (auto j : num[s[i].first.size()]) {
					string t1 = t[j].first, t2 = t[j].second;
					int p1, p2;
					for (int x = 0; x < t1.size(); x++)
						if (t1[x] == 'b')
							p1 = x;
					for (int x = 0; x < t1.size(); x++)
						if (t2[x] == 'b')
							p2 = x;
					ans[j] = dif[p2 - p1 + n];
				}
			}
		}
		for (int i = 1; i <= q; i++)
			cout << ans[i] << '\n';
	}
}

int main (void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	cin >> n >> q;
	int nb = 0;
	for (int i = 1; i <= n; i++) {
		cin >> s[i].first >> s[i].second, mp[{s[i].first, s[i].second}] = true;
		int tmp = 0;
		for (int j = 0; j < s[i].first.size(); j++)
			if (s[i].first[j] == 'b')
				tmp++;
		nb = max(nb, tmp);
		tmp = 0;
		for (int j = 0; j < s[i].first.size(); j++)
			if (s[i].second[j] == 'b')
				tmp++;
		nb = max(nb, tmp);
	}
	if (nb == 1) {
		solveB::solve();
		return 0;
	}
	while (q--) {
		string t1, t2;
		cin >> t1 >> t2;
		int d1 = t1.size() - 1, d2 = 0;
		for (int i = 0; i < t1.size(); i++)
			if (t1[i] != t2[i]) {
				d1 = i;
				break;
			}
		for (int i = t1.size() - 1; i >= 0; i--)
			if (t1[i] != t2[i]) {
				d2 = i;
				break;
			}
		int ans = 0;
		for (int i = 0; i <= d1; i++)
			for (int j = d2; j < t1.size(); j++) {
				string tmp1 = "", tmp2 = "";
				for (int k = i; k <= j; k++)
					tmp1 += t1[k], tmp2 += t2[k];
				if (mp[{tmp1, tmp2}])
					ans++;
			}
		cout << ans << '\n';
	}
	return 0;
}

//L2^2logn做法：枚举替换的左右端点，用map<pair<string,string记录s中的可替换数量
//特殊性质2：有bk[i]记录替换前后b的位置相差为i的s的数量