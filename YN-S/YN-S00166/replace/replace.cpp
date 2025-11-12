#include <bits/stdc++.h>
using namespace std;
const int N = 10004;
int n, q;
vector<pair<string, string>> d;

struct ii {
	int l;
	int r;
	int val;
} c[200005];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		d.push_back({s1, s2});
		int x = s1.find('b'), y = s2.find('b');
		c[i].val = abs(x - y);
		c[i].l = min(x, y);
		c[i].r = s1.size() - max(x, y);
	}
	while (q--) {
		string q1, q2;
		cin >> q1 >> q2;
		if (q1.size() != q2.size()) {
			cout << 0 << endl;
			continue;
		}
		int x = q1.find('b'), y = q2.find('b');
		int cq = abs(x - y);
		long long ans = 0;
		for (int i = 1; i <= n; i++)
			if (c[i].val == cq && d[i - 1].first.size() <= q1.size() && q1.size() - max(x, y) >= c[i].r && min(x, y) >= c[i].l)
				ans++;
		cout << ans << endl;
	}
	return 0;
}