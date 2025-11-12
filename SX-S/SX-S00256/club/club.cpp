#include <bits/stdc++.h>
using namespace std;
int t, n, sum, s[5], p, q;

struct stu {
	int x, y, z, maxi, midi, mini, maxnum, midnum, minnum;
} a[100005];

bool cmp(stu x, stu y) {
	return x.maxnum > y.maxnum;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		memset(a, 0, sizeof a);
		memset(s, 0, sizeof s);
		sum = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
			if (a[i].y == 0)
				p++;
			if (a[i].z == 0)
				q++;
			a[i].maxnum = max(max(a[i].x, a[i].y), a[i].z);
			a[i].minnum = min(min(a[i].x, a[i].y), a[i].z);
			a[i].midnum = a[i].x + a[i].y + a[i].z - a[i].maxnum - a[i].minnum;
			if (a[i].x > a[i].y) {
				if (a[i].x > a[i].z) {
					a[i].maxi = 1;
					if (a[i].y > a[i].z) {
						a[i].midi = 2;
						a[i].mini = 3;
					} else {
						a[i].midi = 3;
						a[i].mini = 2;
					}
				} else {
					a[i].maxi = 3;
					a[i].midi = 1;
					a[i].mini = 2;
				}
			} else if (a[i].x == a[i].y) {
				if (a[i].x < a[i].z) {
					a[i].maxi = 3;
					a[i].midi = 2;
					a[i].mini = 1;
				} else {
					a[i].maxi = 1;
					a[i].midi = 2;
					a[i].mini = 3;
				}
			} else {
				if (a[i].y > a[i].z) {
					a[i].maxi = 2;
					if (a[i].x > a[i].z) {
						a[i].midi = 1;
						a[i].mini = 3;
					} else {
						a[i].midi = 3;
						a[i].mini = 1;
					}
				} else {
					a[i].maxi = 3;
					a[i].midi = 2;
					a[i].mini = 1;
				}
			}
		}
		sort(a + 1, a + 1 + n, cmp);
		if (q == n) {
			if (p == n) {
				for (int i = 1; i <= n / 2; i++) {
					sum += a[i].maxnum;
				}
				cout << sum;
				return 0;
			}
		}
//		for (int i = 1; i <= n; i++) {
//			cout << a[i].maxi << ' ' << a[i].maxnum << ' ' << a[i].midi << ' ' << a[i].midnum << ' ' << a[i].mini << ' ' <<
//			     a[i].minnum << '\n';
//		}
		for (int i = 1; i <= n; i++) {
			if (s[a[i].maxi] < n / 2) {
				if (i != n && a[i + 1].maxi == a[i].maxi   && a[i + 1].maxnum - a[i + 1].midnum > a[i].maxnum - a[i].midnum) {
					sum += a[i].midnum;
					s[a[i].midi]++;
				} else {
					sum += a[i].maxnum;
					s[a[i].maxi]++;
				}
			} else {
				if (s[a[i].midi] < n / 2) {
					if (i != n && a[i + 1].midi == a[i].midi && a[i + 1].midnum - a[i + 1].minnum > a[i].midnum - a[i].minnum) {
						sum += a[i].minnum;
						s[a[i].mini]++;
					} else {
						sum += a[i].midnum;
						s[a[i].midi]++;
					}
				} else {
					sum += a[i].minnum;
					s[a[i].mini]++;
				}
			}
		}
		cout << sum << '\n';
	}
	return 0;
}