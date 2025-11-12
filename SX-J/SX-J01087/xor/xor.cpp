#include <bits/stdc++.h>
using namespace std;
long long n, m, sum[500005], l, r;
long long a[500005], b[500005], id;
long long cnt;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == m)
			cnt++;
		sum[i] = (sum[i - 1] + a[i]);
		if (sum[i] == m)
			cnt++;
	}
	cout << cnt;
	return 0;
}
