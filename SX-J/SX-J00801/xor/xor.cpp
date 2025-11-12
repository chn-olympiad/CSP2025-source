#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+50;
int a[N];
int n, k;
int sum = 0;
int ans = 0;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 1)
			sum++;
	}
	if (n == sum) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == k)
			ans++;
	}
	cout << ans ;
	return 0;
}