#include <bits/stdc++.h>
using namespace std;
int n, a[5010], sum;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum > 20)
		cout << 1;
	else
		cout << 0;
	return 0;
}
