#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n;
	cin >> n;
	for (int q = 1; q < t + 1; q++) {
		for (int i = 1; 1 <= i <= n; i++) {
			int a1, a2, a3;
			cin >> a1 >> a2 >> a3;
			cout << a1 + a2 + a3;
		}
	}
	return 0;
}
