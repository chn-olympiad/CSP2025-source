#include <bits/stdc++.h>
using namespace std;
int a[50001];
int s[50001];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, da = INT_MIN, sum = 0, he;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 2; j <= n; j++) {
			da = INT_MIN;
			for (int k = i; k <= j; k++) {
				da = max(da, a[k]);
			}
			he = s[j] - s[i - 1];
			if (he > 2 * da) {
				sum++;
			}
		}
	}
	sum = sum % 998244353;
	cout << sum << endl;
}
