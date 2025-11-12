#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k, a[100005], sum;

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	cout << sum / k;
	return 0;
}
