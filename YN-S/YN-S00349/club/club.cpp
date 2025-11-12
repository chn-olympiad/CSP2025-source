#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("club.in", "r", stdin );
	freopen("club.out", "w", stdout);
	int n, s = 0;
	int t;
	cin >> t;
	int a[1000], b[1000];
	for (int i = 1; i <= t; i++) {
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> a[j];
			s += a[j];
		}
		cout << s << endl;
	}
	return 0;
}