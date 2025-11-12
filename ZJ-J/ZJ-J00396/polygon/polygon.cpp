#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, cnt=0;
	cin >> n;
	int a[n+5], m = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		m = max(m, a[i]);
	}
	int he[5];
	he[1] = a[1] + a[2];
	he[2] = a[1] + a[3];
	he[3] = a[2] + a[3];
	he[4] = a[1] + a[2] + a[3];
	for(int i = 1; i <= 4; i++) {
		if(he[i] > m * 2) cnt++;
	}
	cout << cnt << "\n";
	return 0;
}

