#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, k, a[500010], qzh[500010], ans;
set<int>s;
int main(int argv, char **argc) {

	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;

	for (int z = 1; z <= n; z++) {
		cin >> a[z];
		qzh[z] = qzh[z - 1] ^ a[z];
	}
	s.insert(0);

	for (int z = 1; z <= n; z++) {
		if (s.find(qzh[z]^k) != s.end()) {
			ans++;
			s.clear();
		}
		s.insert(qzh[z]);
	}
	cout << ans;
	return 0;
}
