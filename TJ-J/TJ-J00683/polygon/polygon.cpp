#include <bits/stdc++.h>
using namespace std;
int a[5010];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int cnt = 0;
	sort(a + 1, a + n + 1); 
	for (int i = 1; i <= n - 2; i++) {
		if (a[i] + a[i + 1] > a[i + 2]) {
			cnt++;
		}
	}
	cout << cnt % 998244353;
	return 0;
}
