#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int a[N];

int main() {
//	freopen("xor.in", "r", stdin);
//	freopen("xor.out", "w", stdout);
	int n, k, cnt = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int i = 2, sum = a[1];
	while (i != n) {
		sum = sum ^a[++i];
		if (sum == k) {
			cnt++;
		}
	}
	if (a[n] == k || a[1] == k) {
		cnt++;
	}
	cout << cnt;
	return 0;
}
