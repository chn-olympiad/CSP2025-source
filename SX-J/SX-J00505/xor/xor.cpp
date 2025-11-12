#include <bits/stdc++.h>
using namespace std;

int n, k, cnt;
int a[300];

int main() {

	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == k) {
			cnt++;
		}

	}

	cout << cnt;

	return 0;
}
