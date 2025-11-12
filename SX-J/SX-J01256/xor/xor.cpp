#include <bits/stdc++.h>
using namespace std;
int n, t, k, sum[100005], a[100005], ans;

int main() {

	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	cin >> a[1];
	sum[1] = a[1];
	for (int i = 2; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	for (int l = 1; l <= n; l++) {
		for (int r = l; r <= n; r++) {
			if ((int)((sum[r] ) ^ (sum[l - 1])) == k) {
				ans++;
				l = r + 1;
			}
		}
	}
	cout << ans;



	return 0;
}
