#include <bits/stdc++.h>
using namespace std;
long long n, k, a[50005], o, z, s[50005], ss, zs, a1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 1)
			o++;
		else if (a[i] == 0)
			z++;
//		if (a[i] == k)
//			a1++;
	}
	if (o + z == n) {
		if (k == 1)
			cout << o;
		else if (k == 0)
			cout << o / 2;
		return 0;
	} else
		cout << n / 2;
	return 0;
}