#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int c = 0, r = 0, num[100010], ans = 0;
	cin >> c >> r ;
	cin >> num[100010];
	for (int i = 0; i <= c; i++) {
		ans++;
		for (int j = 0; j <= r; j++) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}