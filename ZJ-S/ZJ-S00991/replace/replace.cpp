#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

const int N = 2e5 + 10;
const int M = 1e7 + 10;
const i64 MOD = 1e9 + 7;

std::mt19937_64 rnd(time(0));

int n, q;
int l[N], r[N];
int l2[N], r2[N];

i64 base;
i64 p[N];
i64 power[M];

i64 pre[M];

std::string s[N][3], t[N][3];
std::map <i64, std::vector <int> > mp;

i64 hsh (int l, int r) {
	++l, ++r;
	return (pre[r] - pre[l - 1] * power[r - l + 1] % MOD + MOD) % MOD;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	//clock_t st = clock();
	base = rnd() % 1000000000;
	
	std::cin >> n >> q;
	power[0] = 1;
	for (int i = 1; i <= 1e7; ++i) {
		power[i] = power[i - 1] * base % MOD;
	}

	for (int i = 1; i <= n; ++i) {
		std::cin >> s[i][1] >> s[i][2];

		l[i] = -1;
		for (int j = 0; j < s[i][1].size(); ++j) {
			if (s[i][1][j] != s[i][2][j]) {
				if (l[i] == -1) {
					l[i] = j;
				}
				r[i] = j;
			}
			p[i] = (p[i] * base + (s[i][1][j] - 'a')) % MOD;
		}

		i64 ch = 0;
		for (int j = 1; j <= r[i] - l[i] + 1; ++j) {
			ch = (ch + power[j * 2 - 1] * (s[i][1][l[i] + j - 1] - 'a') + power[j * 2] * (s[i][2][l[i] + j - 1] - 'a')) % MOD;
		}
		mp[ch].push_back(i);
	}
	for (int i = 1; i <= q; ++i) {
		std::cin >> t[i][1] >> t[i][2];

		l2[i] = -1;
		for (int j = 0; j < t[i][1].size(); ++j) {
			if (t[i][1][j] != t[i][2][j]) {
				if (l2[i] == -1) {
					l2[i] = j;
				}
				r2[i] = j;
			}
			pre[j + 1] = (pre[j] * base + (t[i][1][j] - 'a')) % MOD;
		}

		i64 ch = 0;
		for (int j = 1; j <= r2[i] - l2[i] + 1; ++j) {
			ch = (ch + power[j * 2 - 1] * (t[i][1][l2[i] + j - 1] - 'a') + power[j * 2] * (t[i][2][l2[i] + j - 1] - 'a')) % MOD;
		}

		int cnt = 0;
		for (auto x : mp[ch]) {
			int b = l2[i] - l[x];
			if (b < 0 || b + s[x][1].size() > t[i][1].size()) {
				continue;
			}
			if (hsh(b, b + s[x][1].size() - 1) == p[x]) {
				++cnt;
			}
		}
		std::cout << cnt << "\n";
	}
	//std::cerr << clock() - st;

	return 0;
}