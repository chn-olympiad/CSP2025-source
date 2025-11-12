#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 998244353ll;
int n, a[50010];
bool  pf1 = 1;

ll qpow(ll aa, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1ll) {
			ans *= aa;
			ans %= M;
		}
		aa = aa * aa % M;
		b >>= 1ll;
	}
	return ans;
}
//ll ans = 0;
//map<int, int>m, lam, lam1;
//set<int>s, s1, las;
int main(int argv, char **argc) {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;

	for (int z = 1; z <= n; z++) {
		cin >> a[z];
//		pf1 &= (a[z] == 1);
	}
	sort(a + 1, a + n + 1);


	if (n == 3) {
		cout << ((a[1] + a[2] > a[3]) ? 1 : 0);
		return 0;
	}

	if (n == 4) {
		int ans = ((a[1] + a[2] > a[3]) ? 1 : 0) + ((a[1] + a[2] > a[4]) ? 1 : 0) + ((a[1] + a[3] > a[4]) ? 1 : 0) + ((
		              a[3] + a[2] > a[4]) ? 1 : 0) + ((
		                      a[1] + a[2] + a[3] > a[4]) ? 1 : 0);
		cout << ans;
		return 0;
	}
	ll ans = 0, fact[5010], fm[5010];
	fact[0] = fact[1] = 1;

	for (ll z = 2; z <= n; z++) {
		fact[z] = fact[z - 1] * z;
		fact[z] %= M;
	}
	fm[n] = qpow(fact[n], M - 2ll);

	for (ll z = n - 1; z > -1; z--) {
		fm[z] = fm[z + 1] * (z + 1ll) % M;
	}

	for (int z = 3; z <= n; z++) {
		ans += (fact[n] * fm[z] % M *fm[n - z] % M);
		ans %= M;
	}
	cout << ans;

//	for (int z = 1; z <= n; z++) {
//		qzh[z] = qzh[z - 1] + a[z];
//	}
//	m[qzh[1]]++;
//	m[qzh[2]]++;
//	m[qzh[2] - qzh[1]]++;
//	s.insert(qzh[1]);
//	s.insert(qzh[2]);
//	s.insert(qzh[2] - qzh[1]);
//	s1 = s;
//	lam = m;
//	las = s;
//	lam1 = lam;
//
//	for (int z = 3; z <= n; z++) {
//		for (auto y : s1) {
//			if (y <= a[z]) {
//				s.erase(y);
//				m.erase(y);
//			} else {
//				ans += ((ll)m[y]);
//				ans %= M;
//			}
//		}
//		s.insert(qzh[z]);
//		m[qzh[z]]++;
//		s1 = s;
//		vector<int>ls, lsy;
//		for (auto y : las) {
//			int pos = qzh[z] - y;
//			ls.push_back(pos);
//			if (pos <= a[z + 1])
//				continue;
//			s.insert(pos);
//			m[pos] += lam[y];
//		}
//		for (int y = 0; y < ls.size(); y++) {
//			las.insert(ls[y]);
//			lam[ls[y]] += lam1[lsy[y]];
//		}
//		lam1 = lam;
//		s1 = s;
//
//	}
//	cout << ans;
	return 0;
}
