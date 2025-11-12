#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

struct xs {
	int a;
	int b;
	int c;
} s[N];

bool cmp(xs a, xs b) {
	if (a.a < b.a)
		return 0;
	else
		return 1;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, t;
	long long ans = 0, lz = 0;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> s[i].a >> s[i].b >> s[i].c;
		}
		if (n == 2) {
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j != i && j <= 3; j++) {
					if (i == 1) {
						ans += s[1].a;
					} else if (i == 2) {
						ans += s[1].b;
					} else if (i == 3) {
						ans += s[1].c;
					}
					if (j == 1) {
						ans += s[2].a;
					} else if (j == 2) {
						ans += s[2].b;
					} else if (j == 3) {
						ans += s[2].c;
					}
					if (ans > lz) {
						lz = ans;
					}
					ans = 0;
				}
			}
			cout << lz ;
		} else {
			sort(s + 1, s + n + 1, cmp);
			for (int i = 1; i <= n / 2; i++) {
				ans += s[i].a;
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
