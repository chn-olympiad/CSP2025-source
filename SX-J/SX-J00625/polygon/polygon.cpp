#include <bits/stdc++.h>
using namespace std;
int n, cnt;
int a[1000000015];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
