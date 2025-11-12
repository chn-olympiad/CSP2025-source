#include <bits/stdc++.h>
using namespace std;
int n, m;

struct T {
	int a1, a2, a3, max, max2, cha;
} t[100005];

bool cmp(T x, T y) {
	if (x.cha == y.cha)
		return x.max > y.max;
	return x.cha > y.cha;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> n;
	for (int k = 1; k <= n; k++) {
		cin >> m;
		int c1 = 0, c2 = 0, c3 = 0, sum = 0;
		for (int i = 1; i <= m; i++) {
			cin >> t[i].a1 >> t[i].a2 >> t[i].a3;
			if (t[i].a1 > t[i].a2 && t[i].a1 > t[i].a3) {
				c1++;
				t[i].max = t[i].a1;
				t[i].max2 = max(t[i].a2, t[i].a3);
				t[i].cha = t[i].max - t[i].max2;
			} else if (t[i].a2 > t[i].a3 && t[i].a2 > t[i].a1) {
				c2++;
				t[i].max = t[i].a2;
				t[i].max2 = max(t[i].a1, t[i].a3);
				t[i].cha = t[i].max - t[i].max2;
			} else if (t[i].a3 > t[i].a1 && t[i].a3 > t[i].a2) {
				c3++;
				t[i].max = t[i].a3;
				t[i].max2 = max(t[i].a1, t[i].a2);
				t[i].cha = t[i].max - t[i].max2;
			}
		}
		sort(t + 1, t + n + 1, cmp);
		if (c1 > m / 2 || c2 > m / 2 || c3 > m / 2) {
			for (int i = 1; i <= m / 2; i++)
				sum += t[i].max2;
			for (int i = (m / 2) + 1; i <= m; i++)
				sum += t[i].max;
		} else {
			for (int i = 1; i <= m; i++)
				sum += t[i].max;
		}
		cout << sum << endl;
	}
	return 0;
}