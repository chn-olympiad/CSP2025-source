#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353ll

const int N = 200005, M = 10005, S = 5000005, P[2] = {131, 47};
ll cf[2][S];
int n, q;
string s1[N], s2[N], t1[N], t2[N];
ll hs1[2][N], hs2[2][N], ht1[2][S], ht2[2][S];
int L[N], R[N];
vector<int>ls[S], rs[S], p[S];
void run1() {
	cf[0][0] = cf[1][0] = 1;
	for (int i = 1; i <= 5000000; ++i)
		cf[0][i] = cf[0][i - 1] * P[0] % mod, cf[1][i] = cf[1][i - 1] * P[1] % mod;
	for (int i = 1; i <= n; ++i) {
//		printf(" %d %d\n", L[i], R[i]);
		for (int j = 0; j < s1[i].size(); ++j) {
			for (int k = 0; k < 2; ++k) {
				hs1[k][i] = (hs1[k][i] * P[k] + s1[i][j] - 'a') % mod;
				hs2[k][i] = (hs2[k][i] * P[k] + s2[i][j] - 'a') % mod;
			}
		}
//		printf(" %lld %lld\n", hs1[0][i], hs2[0][i]);
	}
	for (int i = 1; i <= q; ++i) {
		int ans = 0, l = 0, r = t1[i].size() - 1;
		while (t1[i][l] == t2[i][l])
			++l;
		while (t1[i][r] == t2[i][r])
			--r;
//		printf(" %d %d\n", l, r);
		for (int j = 0; j < t1[i].size(); ++j) {
			for (int k = 0; k < 2; ++k) {
				ht1[k][j + 1] = (ht1[k][j] * P[k] + t1[i][j] - 'a') % mod;
				ht2[k][j + 1] = (ht2[k][j] * P[k] + t2[i][j] - 'a') % mod;
			}
		}
//		printf(" %lld %lld\n", ht1[0][t1[i].size()], ht2[0][t1[i].size()]);
		for (int j = 1; j <= n; ++j) {
			if (L[j] == -1 || r - l != R[j] - L[j] || L[j] > l || s1[j].size() - 1 - R[j] > t1[i].size() - 1 - r)
				continue;
			int rr = r + s1[j].size() - 1 - R[j], sz = s1[j].size();
			if (123 && ((ht1[0][rr + 1] - ht1[0][rr - sz + 1]*cf[0][sz]) % mod + mod) % mod == hs1[0][j]
			        && ((ht1[1][rr + 1] - ht1[1][rr - sz + 1]*cf[1][sz]) % mod + mod) % mod == hs1[1][j]
			        && ((ht2[0][rr + 1] - ht2[0][rr - sz + 1]*cf[0][sz]) % mod + mod) % mod == hs2[0][j]
			        && ((ht2[1][rr + 1] - ht2[1][rr - sz + 1]*cf[1][sz]) % mod + mod) % mod == hs2[1][j])
				++ans;
//			printf("           %d\n", sz);
//			printf("  %lld %lld\n", ((ht1[0][rr + 1] - ht1[0][rr - sz + 1]*cf[0][sz]) % mod + mod) % mod, hs1[0][j]);
//			printf("  %lld %lld\n", ((ht1[1][rr + 1] - ht1[1][rr - sz + 1]*cf[1][sz]) % mod + mod) % mod, hs1[1][j]);
//			printf("  %lld %lld\n", ((ht2[0][rr + 1] - ht2[0][rr - sz + 1]*cf[0][sz]) % mod + mod) % mod, hs2[0][j]);
//			printf("  %lld %lld\n", ((ht2[1][rr + 1] - ht2[1][rr - sz + 1]*cf[1][sz]) % mod + mod) % mod, hs2[1][j]);
		}
		printf("%d\n", ans);
	}
}
void run2() {
	for (int i = 1; i <= n; ++i) {
		if (L[i] == -1)
			continue;
		ls[R[i] - L[i]].push_back(L[i]), rs[R[i] - L[i]].push_back(s1[i].size() - R[i]), p[R[i] - L[i]].push_back(i);
	}
	for (int i = 1; i <= q; ++i) {
		int ans = 0, l = 0, r = t1[i].size() - 1;
		while (t1[i][l] == t2[i][l])
			++l;
		while (t1[i][r] == t2[i][r])
			--r;
		for (int j = 0; j < ls[r - l].size(); ++j) {
			if (ls[r - l][j] <= l && rs[r - l][j] <= t1[i].size() - r && s1[p[r - l][j]][ls[r - l][j]] == t1[i][l]) {
				++ans;
//				cout << s1[p[r - l][j]] << ' ' << s2[p[r - l][j]] << ' ' << t1[i] << ' ' << t2[i] << '\n';
			}
		}
		printf("%d\n", ans);
	}
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> s1[i] >> s2[i];
	for (int i = 1; i <= n; ++i) {
		if (s1[i] == s2[i])
			L[i] = -1;
		else {
			L[i] = 0, R[i] = s1[i].size() - 1;
			while (s1[i][L[i]] == s2[i][L[i]])
				++L[i];
			while (s1[i][R[i]] == s2[i][R[i]])
				--R[i];
		}
	}
	for (int i = 1; i <= q; ++i)
		cin >> t1[i] >> t2[i];
	if ((long long)n * q <= 100000000)
		run1();
	else
		run2();
//	run1(), run2();
	return 0;
}
