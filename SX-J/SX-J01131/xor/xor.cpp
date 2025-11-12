#include <bits/stdc++.h>
using namespace std;
const int MAXK = 2.1e6 + 5;
int a, sum, prek[MAXK];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	memset(prek, -1, sizeof(prek));
	int n, k, r, ans = 0;
	cin >> n >> k;
	prek[0] = 0;
	r = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		sum ^= a;
//		cout << i << "," << sum << "," << prek[sum ^k] << "," << r << endl;
		if (prek[sum ^ k] + 1 > r) {
			ans++;
			r = i;
		}
		prek[sum] = i;
	}
	cout << ans;
	return 0;
}
