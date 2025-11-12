#include <bits/stdc++.h>
using namespace std;

struct students {
	int score, id;
} a[186];

bool cmp(students x, students y) {
	return x.score > y.score;
}
int m, n;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int nm = n * m, cnt = 0;
	for (int i = 1; i <= nm; i++) {
		cin >> a[i].score;
		a[i].id = i;
	}
	sort(a + 1, a + nm + 1, cmp);
	for (int i = 1; i <= m; i++) {
		if (i % 2) {
			for (int j = 1; j <= n; j++) {
				cnt++;
				if (a[cnt].id == 1) {
					cout << i << ' ' << j;
					return 0;
				}
			}
		} else {
			for (int j = n; j >= 1; j--) {
				cnt++;
				if (a[cnt].id == 1) {
					cout << i << ' ' << j;
					return 0;
				}
			}
		}
	}
	return 0;
}
