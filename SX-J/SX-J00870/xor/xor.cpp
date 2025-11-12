#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], yh[500005], ans;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	yh[1] = a[1];
	for (int i = 2; i <= n; i++)
		yh[i] = (yh[i - 1] ^ a[i]);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - i + 1; j++) {
			if (a[i] == k && j == 1) {
				ans++;
				break;
			}
			if ((yh[i + j - 1]^yh[i - 1]) == k) {
				ans++;
				i = i + j - 1;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
