#include <bits/stdc++.h>

using namespace std;

const long long k = 13331, mod = 1e9 + 7;

long long K[5000005];

long long Hash1(string s) {
	long long res = 0, kk = 1;
	for (int i = 0; i < s.size(); ++i) {
		res = (res + (s[i] - 'a' + 1 + mod) % mod * kk % mod) % mod;
		(kk *= k) %= mod;
	}
	return (res + mod) % mod;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	vector<string> s(n + 1), s2(n + 1);
	vector<long long> hash1(n + 1), hash2(n + 1);
	K[0] = 1;
	for (int i = 1; i <= 5000005; ++i) {
		K[i] = K[i - 1] * k % mod;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> s[i] >> s2[i];
		hash1[i] = Hash1(s[i]), hash2[i] = Hash1(s2[i]);
	}
	
	while (q--) {
		string a, b;
		cin >> a >> b;
		vector<long long> ha(a.size() + 1);
		long long hb = Hash1(b);
		for (int i = 0; i < a.size(); ++i) {
			ha[i + 1] = (ha[i] + (a[i] - 'a' + 1 + mod) % mod * K[i] % mod) % mod;
		}
		int ans = 0;
		for (int i = 0; i < a.size(); ++i) {
			for (int j = 1; j <= n; ++j) {
				if (i + s[j].size() <= a.size() && (hash1[j] * K[i]) % mod == (ha[i + s[j].size()] - ha[i] + mod) % mod) {
					if ((ha[i] + hash2[j] * K[i] % mod + (ha[a.size()] - ha[i + s[j].size()] + mod) % mod) % mod == hb) {
						ans++;
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
