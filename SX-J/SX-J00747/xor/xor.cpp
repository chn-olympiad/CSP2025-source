#include <bits/stdc++.h>
using namespace std;
int n, k, ans;
int a[500005], s[500005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i == 1) {
			s[i] = a[i];
			continue;
		}
		s[i] = s[i - 1] ^ a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if ((s[i - 1]^s[j] ) == k) {
				ans++;
				i = j;
			}
		}
	}
	cout << ans;
	return 0;
}
