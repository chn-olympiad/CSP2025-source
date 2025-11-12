#include <bits/stdc++.h>
using namespace std;
int n, k, a[200005], sum;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == k)
			sum++;
	}


	cout << sum;


	return 0;
}
