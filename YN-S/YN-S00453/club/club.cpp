#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n;
	cin >> t;
	for (; t > 0; t--) {
		int s = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			s += max({a, b, c});
		}
		cout << s << endl;
	}

	return 0;
}