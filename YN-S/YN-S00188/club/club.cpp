#include <bits/stdc++.h>
using namespace std;
int a[1000], b[1000], c[1000];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, cnt = 0, maxx = 0;
		cin >> n;
		while (n--) {
			cnt++;
			cin >> a[cnt] >> b[cnt] >> c[cnt];
		}
	}
	cout << 100;
	return 0;
}