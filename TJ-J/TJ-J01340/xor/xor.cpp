#include <bits/stdc++.h>

using namespace std;

int n, k, res, a[500005];

int main () {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 1) res++;
	}
	if (k == 0) cout << n / 2, exit (0);
	cout << res;
	fclose (stdin);
	fclose (stdout);
	return 0;
}
