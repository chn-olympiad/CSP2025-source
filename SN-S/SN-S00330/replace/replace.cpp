#include <bits/stdc++.h>

using namespace std;
constexpr unsigned long long mod = (1ull << 61) - 1, base = 31;
int n, q;
array<pair<basic_string<char>, basic_string<char>>, 200005> s;

pair<int, int> get_common(basic_string<char> &s, basic_string<char> &t) {
	int l = 0, r = s.size() - 1;
	while (l < s.size() && s[l] == t[l]) {
		l++;
	}
	
	while (r >= 0 && s[r] == t[r]) {
		r--;
	}
	return {l, r};
}

unsigned long long hash_range(basic_string<char> &s, int l, int r) {
	unsigned long long res = 0;
	for (int i = l; i <= r; ++i) {
		res = res * base % mod + (s[i] - 'a');
		if (res >= mod) {
			res -= mod;
		}
	}
	return res;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> q;
	
	struct info {
		int l_len, r_len;
		unsigned long long vl, vr;
		
		info() = default;
		
		info(int l, int r, unsigned long long v1, unsigned long long v2) : l_len(l), r_len(r), vl(v1), vr(v2) {}
	};
	
	map<pair<unsigned long long, unsigned long long>, vector<info>> str;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i].first >> s[i].second;
		
		auto range = get_common(s[i].first, s[i].second);
		int l = range.first, r = range.second;
		
		auto hash_v1 = hash_range(s[i].first, l, r), hash_v2 = hash_range(s[i].second, l, r), vr = hash_range(s[i].first, r + 1, s[i].first.size() - 1);
		
		unsigned long long v = 0;
		for (int j = l - 1; j >= 0; --j) {
			v = (v * base % mod + (s[i].first[j] - 'a'));
			
			if (v >= mod) {
				v -= mod;
			}
		}
		
		str[{hash_v1, hash_v2}].emplace_back(l, s[i].first.size() - r - 1, v, vr);
	}
	
	for (int _ = 0; _ < q; ++_) {
		basic_string<char> t1, t2;
		cin >> t1 >> t2;
		
		if (t1.size() != t2.size()) {
			cout <<"0\n";
		} else {
			auto range = get_common(t1, t2);
			int l = range.first, r = range.second;
			
			auto hash_v1 = hash_range(t1, l, r), hash_v2 = hash_range(t2, l, r);
			
			auto &cans = str[{hash_v1, hash_v2}];
			vector<unsigned long long> prefix(t1.size(), 0), suffix(t1.size(), 0);
			for (int i = r + 1; i < t1.size(); ++i) {
				suffix[i] = suffix[i - 1] * base % mod + (t1[i] - 'a');
				
				if (suffix[i] >= mod) {
					suffix[i] -= mod;
				}
			}
			
			for (int i = l - 1; i >= 0; --i) {
				prefix[i] = prefix[i + 1] * base % mod + (t1[i] - 'a');
				
				if (prefix[i] >= mod) {
					prefix[i] -= mod;
				}
			}
			
			int ans = 0;
			for (auto i : cans) {
				if (i.l_len <= l && i.r_len <= t1.size() - r - 1) {
					if (i.vl == prefix[l - i.l_len] && i.vr == suffix[r + i.r_len]) {
						ans++;
					}
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
