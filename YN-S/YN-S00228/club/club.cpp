#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n;
	cin >> t;
	int sum = 0;
	int sc[10] = {};
	for (int i = 0; i < t; i++) {
		cin >> n;
		int a1 = 0, a2 = 0, a3 = 0;
		for (int j = 0; j < n; j++) {
			cin >> a1 >> a2 >> a3;
			sum += max(max(a1, a2), a3);
		}
		sc[i] = sum;
		sc[i]
		sum = 0;
	}
	for (int i = 0; i < 10; i++) {
		cout << sc[i];
	}
	return 0;
}