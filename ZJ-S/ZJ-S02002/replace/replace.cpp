#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 6, base = 131;
set <pair <unsigned long long, unsigned long long> > stt;
unsigned long long H1[N], H2[N], p[3 * N];
int n, q, ans;
unsigned long long getHash1(int l, int r) {
	if (!l) return H1[r];
	return H1[r] - H1[l - 1] * p[r - l + 1];
}
unsigned long long getHash2(int l, int r) {
	if (!l) return H2[r];
	return H2[r] - H2[l - 1] * p[r - l + 1];
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	const int qq = q;
	for (int i = 1; i <= n; ++i) {
		string c1, c2;
		cin >> c1 >> c2;
		unsigned long long hash1 = 0ull, hash2 = 0ull;
		for (int j = 0; j < c1.size(); ++j)
			hash1 = hash1 * base + c1[j] - 'a' + 1;
		for (int j = 0; j < c2.size(); ++j)
			hash2 = hash2 * base + c2[j] - 'a' + 1;
		if (!stt.count({hash1, hash2}))
			stt.insert({hash1, hash2});
	}
	p[0] = 1;
	for (int i = 1; i <= 3 * N; ++i)
		p[i] = p[i - 1] * base;
	for (int o = 1; o <= qq; ++o) {
		memset(H1, 0, sizeof(H1)), memset(H2, 0, sizeof(H2));
		ans = 0;
		string t1, t2;
		cin >> t1 >> t2;
		H1[0] = t1[0] - 'a' + 1, H2[0] = t2[0] - 'a' + 1;
		int st = -1, ed = -1;
		for (int i = 0; i < t1.size(); ++i)
			if (t1[i] != t2[i]) {
				if (st == -1) st = i;
				ed = i;
			}
		for (int i = 1; i < t1.size(); ++i)
			H1[i] = H1[i - 1] * base + t1[i] - 'a' + 1;
		for (int i = 1; i < t2.size(); ++i)
			H2[i] = H2[i - 1] * base + t2[i] - 'a' + 1;
		for (int len = ed - st; len <= t1.size(); ++len) {
			for (int l = max(ed - len, 0); l < t1.size(); ++l) {
				int r = l + len;
				if (stt.count({getHash1(l, r), getHash2(l, r)}))
					++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}