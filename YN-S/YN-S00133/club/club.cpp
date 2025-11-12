#include <bits/stdc++.h>
using namespace std;
int t, n, ans, top, cnt[5], siz[5], b[100010], s[4][100010];

struct xyz {
	int b[4], ma, m, mi;
} a[100010];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;

	while (t--) {
		cin >> n;
		memset(s, 0, sizeof(s));
		memset(b, 0, sizeof(b));
		memset(siz, 0, sizeof(siz));
		memset(cnt, 0, sizeof(cnt));
		ans = top = 0;

		for (int i = 1; i <= n; i++) {

			cin >> a[i].b[1] >> a[i].b[2] >> a[i].b[3];
			a[i].ma = max(a[i].b[1], max(a[i].b[2], a[i].b[3]));
			a[i].mi = 999999;
			a[i].mi = min(a[i].b[1], min(a[i].b[2], a[i].b[3]));

			if (a[i].b[1] == a[i].ma && a[i].b[2] == a[i].mi) {
				a[i].m = a[i].b[3];
			} else if (a[i].b[1] == a[i].mi && a[i].b[2] == a[i].ma) {
				a[i].m = a[i].b[3];
			} else if (a[i].b[2] == a[i].ma && a[i].b[3] == a[i].mi) {
				a[i].m = a[i].b[1];
			} else if (a[i].b[2] == a[i].mi && a[i].b[3] == a[i].ma) {
				a[i].m = a[i].b[1];
			} else if (a[i].b[1] == a[i].ma && a[i].b[3] == a[i].mi) {
				a[i].m = a[i].b[2];
			} else if (a[i].b[1] == a[i].mi && a[i].b[3] == a[i].ma) {
				a[i].m = a[i].b[2];
			}

			ans += a[i].ma;

			if (a[i].ma == a[i].b[1]) {
				s[1][++siz[1]] = i;
			} else if (a[i].ma == a[i].b[2]) {
				s[2][++siz[2]] = i;
			} else if (a[i].ma == a[i].b[3]) {
				s[3][++siz[3]] = i;
			}
		}

		if (siz[1] > n / 2) {
			for (int i = 1; i <= siz[1]; i++) {

				b[++top] = a[s[1][i]].ma - a[s[1][i]].m;
			}

			sort(b + 1, b + top + 1, cmp);

			while (siz[1] > n / 2) {
				ans -= b[top];
				top--;
				siz[1]--;
			}
		} else if (siz[2] > n / 2) {
			for (int i = 1; i <= siz[2]; i++) {

				b[++top] = a[s[2][i]].ma - a[s[2][i]].m;
			}

			sort(b + 1, b + top + 1, cmp);

			while (siz[2] > n / 2) {
				ans -= b[top];
				top--;
				siz[2]--;
			}
		} else if (siz[3] > n / 2) {
			for (int i = 1; i <= siz[3]; i++) {

				b[++top] = a[s[3][i]].ma - a[s[3][i]].m;
			}

			sort(b + 1, b + top + 1, cmp);

			while (siz[3] > n / 2) {
				ans -= b[top];
				top--;
				siz[3]--;
			}
		}

		cout << ans << "\n";
	}

	return 0;
}