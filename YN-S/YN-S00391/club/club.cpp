#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;

struct club {
	long long a, b, c;
} a[N];
long long n, t, maxn;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for (int i = 0; i <= t - 1; i++) {
		cin >> n;
		for (int j = 0; j <= n - 1; i++) {
			cin >> a[j].a >> a[j].b >> a[j].c;
		}
		for (int j = 0; j <= n - 1; j++) {
			for (int l = 0; l <= n - 1; l++) {
				for (int h = 0; h <= n - 1; h++) {
					if (a[j].a + a[l].b + a[h].c > maxn) {
						maxn = a[j].a + a[l].b + a[h].c;
					}
				}
			}
		}
	}
	return 0;
}