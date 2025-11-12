#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+3;
int n, k, a[N], b[N], sum = 0;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == k) {
			sum++;
		}
	}
	cout << sum;
	return 0;
}