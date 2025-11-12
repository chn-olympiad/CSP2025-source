#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
#define N 500005
int n, k, a, f[N], ans, t;
map<int, int> mp;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> t;
		a ^= t;
		f[i] = f[i - 1];
		if (mp[a ^ k] || a == k)
			f[i] = max(f[i], f[mp[a ^ k]] + 1);
		mp[a] = i;
		ans = max(ans, f[i]);
	}
	cout << ans << endl;
	return 0;
}
