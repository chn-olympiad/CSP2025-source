#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, k, p, t;
	cin >> n >> m;
	int a[n * m];
	int s[n * m];
	cin >> a[n * m];
	for (int i = 1; i <= n * m; i++) {
		for (int j = 0; j <= i - 1; j++) {
			if (a[i] > a[j])
				s[i] = a[i - 1];
		}
	}
	if (k <= n) {
		s[k] = k;
		s[p] = 1;
	} else (k > n);
	{
		t = k / n;
		s[k] = k - n * t;
		s[p] = t;

	}
	cout << s[k] << s[p];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
