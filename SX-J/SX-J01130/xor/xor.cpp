#include <bits/stdc++.h>
using namespace std;
int n, k, a[10000], sum = 0;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	cout << sum / k - 1 ;
	return 0;
}
