#include <bits/stdc++.h>
using namespace std;
long long n, k, a[500005], sum, s[500005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == k and s[a[i]] == 0) {
			sum++;
			s[a[i]] = 1;
			break;
		}
		for (int j = i; j <= n; j++) {
			long long ans;
			if (s[a[j]] == 0) {
				ans ^= a[j];
				s[a[j]] = 1;
				if (ans == k) {
					sum++;
					break;
				}
			} else {
				for (int l = i; l <= j - 1; l++) {
					s[a[l]] = 0;
				}
				break;
			}
			if (j == n) {
				for (int l = i; l <= n; l++) {
					s[a[l]] = 0;
				}
			}

		}
	}
	cout << sum;
	return 0;
}
