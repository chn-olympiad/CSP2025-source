#include <bits/stdc++.h>
using namespace std;

void file() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
}

int n, k, p, a[500005], f[500005];

unordered_map<int, int> mp;

int main() {
	file();
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= n; i++) {
  		p ^= a[i];
		if (p == k)
			f[i] = 1;
		if (mp[k ^ p])
			f[i] = max(f[i], f[mp[k ^ p]] + 1);
		f[i] = max(f[i - 1], f[i]);
		mp[p] = i;
	}
	cout << f[n];
	return 0;
}
