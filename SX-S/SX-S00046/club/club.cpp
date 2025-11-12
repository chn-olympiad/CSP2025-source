#include <bits/stdc++.h>
using namespace std;
int a[10010][5];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n;
		int sum = 0;
		cin >> n;
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= 3; k++) {
				cin >> a[j][k];
			}
		}
		for (int j = 1; j <= n; j++) {
			sum += a[j][1];
		}
		cout << sum << endl;
	}
	return 0;
}
