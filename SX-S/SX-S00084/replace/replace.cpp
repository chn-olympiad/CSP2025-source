#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 998244353;
ll n, q;
string s, t;
ll hash1[200005], hash2[200005], siz1[200005], siz2[200005];
int hasht1[5000005], hasht2[5000005], t131[5000005];

ll hashh(string xx) {
	ll hashnum = 0;
	for (ll i = 0; i <= (ll)xx.size(); i++) {
		hashnum = (hashnum * 131 + xx[i]) % mod;
	}
	return hashnum % mod;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (ll i = 1; i <= n; i++) {
		cin >> s >> t;
		hash1[i] = hashh(s);
		hash2[i] = hashh(t);
		siz1[i] = s.size();
		siz2[i] = t.size();
	}
	t131[0] = 1;
	for (ll i = 1; i <= 5000000; i++)
		t131[i] = (t131[i - 1] * 131) % mod;
	for (ll i = 1; i <= q; i++) {
		cin >> s >> t;
		if (s.size() != t.size()) {
			cout << 0 << endl;
			continue;
		}
		ll ans = 0;
		hasht1[0] = s[0];
		hasht2[0] = t[0];
		for (ll j = 1; j <= n; j++) {
			for (ll k = siz1[j]; k < (ll)s.size(); k++) {
				if (hasht1[k - siz1[j]] != hasht2[k - siz1[j]])
					break;
				if (((hasht1[k] - hasht1[k - siz1[j]]*t131[siz1[j]] % mod) % mod + mod) % mod == hash1[j]
				        && ((hasht2[k] - hasht2[k - siz1[j]]*t131[siz1[j]] % mod) % mod + mod) % mod == hash2[j]) {
					if (((hasht1[s.size() - 1] - hasht1[k]*t131[s.size() - 1 - k] % mod) % mod + mod) % mod == ((
					            hasht2[s.size() - 1] - hasht2[k]*t131[s.size() - 1 - k] % mod) % mod + mod) % mod) {
						ans++;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
