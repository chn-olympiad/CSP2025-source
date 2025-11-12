#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int t;
struct node {
	int maxx = 0;
} a[N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ans = 0, sum = 0;
		for (int i = 1; i <= n; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			int g[5] = {0};
			if (x > y && x > z) {
				a[++ans].maxx = x;
				g[1]++;
				if (g[1] > n / 2) {
					a[ans].maxx = max(y, z);
				}
			} else if (y > x && y > z) {
				a[++ans].maxx = y;
				g[2]++;
				if (g[2] > n / 2) {
					a[ans].maxx = max(x, z);
				}
			} else {
				a[++ans].maxx = z;
				g[3]++;
				if (g[3] > n / 2) {
					a[ans].maxx = max(x, y);
				}
			}

			sum += a[ans].maxx;
		}
		cout << sum << endl;
	}
	return 0;
}