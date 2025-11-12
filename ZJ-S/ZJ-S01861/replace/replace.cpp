#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
const int maxn = 2e5 + 10, maxm = 5e6 + 10, base = 131;
int n, q, cnt, tp[maxn], sp = 1;
string s1, s2;
inline string read() {
	string res = ""; char c = getchar();
	while (c < 'a' || c > 'z') c = getchar();
	while (c >= 'a' && c <= 'z') {
		res += c, c = getchar();
	}
	return res;
}
map<pair<unsigned long long, unsigned long long>, int> mp;
string L[maxn], R[maxn];
vector<int> vec[maxn];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int N = 1; N <= n; N++) {
		s1 = read(), s2 = read();
		if (s1 == s2) {
			continue;
		}
		int len = s1.size(), i = 0, j = len - 1;
		while (s1[i] == s2[i]) i++;
		while (s1[j] == s2[j]) j--;
		unsigned long long hsh1 = 0, hsh2 = 0;
		for (int k = i; k <= j; k++) {
			hsh1 = hsh1 * base + s1[k];
			hsh2 = hsh2 * base + s2[k];
		}
		if (!mp.count({hsh1, hsh2})) {
			mp[{hsh1, hsh2}] = ++cnt;
		}
		tp[N] = mp[{hsh1, hsh2}];
		vec[tp[N]].push_back(N);
		for (int k = 0; k <= i - 1; k++) {
			L[N] += s1[k];
		}
		for (int k = j + 1; k < len; k++) {
			R[N] += s1[k];
		}
	}
	for (int Q = 1; Q <= q; Q++) {
		s1 = read(), s2 = read();
		if (s1.size() != s2.size()) {
			puts("0");
			continue;
		}
		int len = s1.size(), i = 0, j = len - 1;
		while (s1[i] == s2[i]) i++;
		while (s1[j] == s2[j]) j--;
		unsigned long long hsh1 = 0, hsh2 = 0;
		for (int k = i; k <= j; k++) {
			hsh1 = hsh1 * base + s1[k];
			hsh2 = hsh2 * base + s2[k];
		}
		if (!mp.count({hsh1, hsh2})) {
			puts("0");
			continue;
		}
		int id = mp[{hsh1, hsh2}], ans = 0;
		for (int P = 0; P < vec[id].size(); P++) {
			int p = vec[id][P];
			int ok = 1, x = L[p].size(), y = R[p].size();
			for (int k = 0; k < x; k++) {
				if (L[p][k] != s1[i - x + k]) {
					ok = 0; break;
				}
			}
			if (!ok) continue;
			for (int k = 0; k < y; k++) {
				if (R[p][k] != s1[j + 1 + k]) {
					ok = 0; break;
				}
			}
			if (ok) {
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}