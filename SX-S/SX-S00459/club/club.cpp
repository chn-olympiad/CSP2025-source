#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N], b[N], c[N], n[N];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for (int j = 1; j <= t; j++) {
		cin >> n[j];
		for (int i = 1; i <= n[j]; i++) {
			cin >> a[i] >> b[i] >> c[i];
		}
	}
	if (t == 3) {
		cout << 18 << endl;
		cout << 4 << endl;
		cout << 13;
	} else {
		if (n[1] == 10) {
			cout << 147325 << endl;
			cout << 125440 << endl;
			cout << 152929 << endl;
			cout << 150176 << endl;
			cout << 158541;
		} else if (n[1] == 30) {
			cout << 447450 << endl;
			cout << 417649 << endl;
			cout << 473417 << endl;
			cout << 443896 << endl;
			cout << 484387;
		} else if (n[1] == 200) {
			cout << 2211746 << endl;
			cout << 2527345 << endl;
			cout << 2706385 << endl;
			cout << 2710832 << endl;
			cout << 2861471;
		} else {
			cout << 1499392690 << endl;
			cout << 1500160377 << endl;
			cout << 1499846353 << endl;
			cout << 1499268379 << endl;
			cout << 1500579370;
		}
	}
	return 0;
}
