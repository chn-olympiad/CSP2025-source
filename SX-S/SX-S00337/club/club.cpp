#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

struct stu {
	int a, b, c;
} d[N];
long long t, e[4], ans;

bool cmp(stu a, stu b) {
	if (a.a != b.a)
		return a.a > b.a;
	if (a.b != b.b)
		return a.b > b.b;
	return a.c > b.c;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		e[1] = e[2] = e[3] = 0;
		ans = 0;
		for (int i = 1; i <= n; i++)
			cin >> d[i].a >> d[i].b >> d[i].c;
		sort(d + 1, d + 1 + n, cmp);
		for (int i = 1; i <= n; i++) {
			int num = max(d[i].a, max(d[i].b, d[i].c));
			int num1 = min(d[i].a, min(d[i].b, d[i].c));
			if (num == d[i].a) {
				e[1]++;
				ans += d[i].a;
				if (e[1] > n / 2) {
					e[1]--;
					ans -= d[i].a;
					if (num1 == d[i].b) {
						e[3]++;
						ans += d[i].c;
					} else {
						e[2]++;
						ans += d[i].b;
					}
				}
			}
			if (num == d[i].b) {
				e[2]++;
				ans += d[i].b;
				if (e[2] > n / 2) {
					e[2]--;
					ans -= d[i].b;
					if (num1 == d[i].a) {
						e[3]++;
						ans += d[i].c;
					} else {
						e[1]++;
						ans += d[i].a;
					}
				}
			}
			if (num == d[i].c) {
				e[3]++;
				ans += d[i].c;
				if (e[3] > n / 2) {
					e[3]--;
					ans -= d[i].c;
					if (num1 == d[i].b) {
						e[1]++;
						ans += d[i].a;
					} else {
						e[2]++;
						ans += d[i].b;
					}
				}
			}
		}
		cout << ans ;
	}
	return 0;
}
