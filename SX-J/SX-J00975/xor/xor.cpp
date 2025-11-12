#include <bits/stdc++.h>
using namespace std;

int n, k, a[500010], s[500010];
int ans = 0, l = 1;

int main() {
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	cin >> n >> k;
	int r = n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] = (a[i] ^ a[i - 1]);
		s[i] = a[i] + s[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (s[i] - s[j] == k) {
				l = j;
				r = i;
			}
		}
	}
	cout << n;
	return 0;
	fclose(stdin);
	fclose(stdout);
}