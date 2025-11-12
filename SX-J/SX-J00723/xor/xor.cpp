#include <bits/stdc++.h>
using namespace std;

int n, k, a[500001], ans, answer;

void findd(int l) {
	if (l > n) {

		return ;
	}
	int f = 0;

	for (int i = l; i <= n; i++) {
		int sum = a[l];
		for (int j = l + 1; j <= i; j++) {
			sum = ( sum ^a[j]);
		}

		if (sum == k) {
			findd(i + 1);
			ans++;



			f = 1;
			return ;

		}
	}
	if (!f)
		findd(l + 1);
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	findd(1);


	cout << ans;
	return 0;
}
