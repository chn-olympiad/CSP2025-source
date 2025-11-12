#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 5;
const int M = 5e6 + 5;
const ll base = 2137;
const ll mod = (ll)1e18 + 3;

int n, m;

ll f[M], H[M];

string s1[N], s2[N], t1, t2, t;

unordered_map<ll, int> mp, tmp;
vector<pair<ll, ll>> vec[M];

inline ll query(int l, int r) {
	return (H[(r + 1) << 1] + (__int128)H[l << 1] * (mod - f[(r - l + 1) << 1])) % mod;
}

int main() {
	assert(freopen("replace.in", "r", stdin));
	assert(freopen("replace.out", "w", stdout));
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> s1[i] >> s2[i];
	}
	f[0] = 1;
	for (int i = 1; i < M; ++i) {
		f[i] = (__int128)f[i - 1] * base % mod;
	}
	for (int i = 1; i <= n; ++i) {
		if (s1[i] == s2[i]) {
			continue;
		}
		int k = s1[i].size(), cnt = 1;
		ll h = 0;
		int p = -1;
		for (int j = 0; j < k; ++j) {
			if (s1[i][j] != s2[i][j]) {
				p = j;
			}
		}
		for (int j = 0; j < k; ++j) {
			ll th = h;
			if (s1[i][j] != s2[i][j]) {
				th = 0;
			}
			h = ((__int128)h * base + s1[i][j]) % mod;
			h = ((__int128)h * base + s2[i][j]) % mod;
			vec[j].emplace_back(h, th);
		}
		++tmp[h];
	}
	for (int i = 0; !vec[i].empty(); ++i) {
		for (auto p: vec[i]) {
			ll h = p.first, th = p.second;
			mp[h] = mp[th] + tmp[h];
		}
	}
	while (m--) {
		cin >> t1 >> t2;
		t = "";
		int k = t1.size(), p = -1;
		for (int i = 0; i < k; ++i) {
			if (t1[i] != t2[i]) {
				p = i;
			}
			t += t1[i];
			t += t2[i];
		}
		for (int i = 0; i < (k << 1); ++i) {
			H[i + 1] = ((__int128)H[i] * base + t[i]) % mod;
		}
		int res = 0;
		for (int i = 0; i < k; ++i) {
			if (mp.find(query(i, p)) == mp.end()) {
				if (t1[i] != t2[i]) {
					break;
				}
				continue;
			}
			int l = p, r = k - 1;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (mp.find(query(i, mid)) != mp.end()) {
					l = mid + 1;
				} else {
					r = mid - 1;
				}
			}
			res += mp[query(i, r)];
			if (t1[i] != t2[i]) {
				break;
			}
		}
		cout << res << "\n";
	}
	return 0;
}