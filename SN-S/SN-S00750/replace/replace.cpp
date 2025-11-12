#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
const int N = 2e5 + 5, M = 5e6 + 5;
int n, q;
const ull bas = 13331;
int len[N];
ull fac[M];
ull s1[M], s2[M];
ull h1[M], h2[M];
ull gtt1(int l, int r) {
	return h1[r] - h1[l - 1] * fac[r - l + 1]; 
}
ull gtt2(int l, int r) {
	return h2[r] - h2[l - 1] * fac[r - l + 1];
}

struct Node {
	string s1, s2;
	int l;
	bool operator < (const Node &a) const {
		return l > a.l;
	}
} e[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	fac[0] = 1;
	for (int i = 1; i < M; i++) fac[i] = fac[i - 1] * bas;
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> e[i].s1 >> e[i].s2, e[i].l = e[i].s1.size();
	sort(e + 1, e + 1 + n);
	for (int i = 1; i <= n; i++) {
		string t1 = e[i].s1, t2 = e[i].s2;
		int l = t1.size();
		for (int j = 0; j < l; j++) s1[i] = s1[i] * bas + t1[j], s2[i] = s2[i] * bas + t2[j];
		len[i] = l;
	}
	while (q--) {
		string t1, t2;
		cin >> t1 >> t2;
		int lenn = t1.size(), ans = 0;
		t1 = " " + t1, t2 = " " + t2;
		for (int i = 1; i <= lenn; i++) h1[i] = h1[i - 1] * bas + t1[i], h2[i] = h2[i - 1] * bas + t2[i];
		int pl = 0, pr = lenn;
		for (int i = 1; i <= lenn; i++)
			if (t1[i] != t2[i]) {
				pl = i;
				break;
			}
		for (int i = lenn; i; --i)
			if (t1[i] != t2[i]) {
				pr = i;
				break;
			}
		for (int i = 1; i <= n; i++) {
			if (len[i] < pr - pl + 1) break;
			int w = max(1, pr - len[i] + 1);
			for (int l = w; l <= pl; l++) {
				int r = l + len[i] - 1;
				if (r > lenn) break;
				if (s1[i] == gtt1(l, r) && s2[i] == gtt2(l, r)) ++ans;
			}
		}
		cout << ans <<'\n';
	}
	return 0;
}
