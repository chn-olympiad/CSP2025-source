#include <bits/stdc++.h>
using namespace std;
int t;
int ans[100005][4];

struct node {
	int a, b, c;
} x[100005];

bool cmp1(node c1, node c2) {
	return max(c1.a, max(c1.b, c1.c)) > max(c2.a, max(c2.b, c2.c));
}

bool cmp2(node c1, node c2) {
	return c1.b > c2.b;
}

bool cmp3(node c1, node c2) {
	return c1.c > c2.c;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int lans = -10;
		int a1 = 0, b2 = 0, c3 = 0;
		for (int i = 1; i <= n; i++) {
			cin >> x[i].a >> x[i].b >> x[i].c;
		}
		sort(x + 1, x + n + 1, cmp1);
		for (int i = 1; i <= n; i++) {
			ans[i][1] = max(ans[i - 1][1], max(ans[i - 1][2], ans[i - 1][3]));
			ans[i][2] = max(ans[i - 1][1], max(ans[i - 1][2], ans[i - 1][3]));
			ans[i][3] = max(ans[i - 1][1], max(ans[i - 1][2], ans[i - 1][3]));
			if (a1 <= n / 2) {
				ans[i][1] = max(ans[i - 1][1], max(ans[i - 1][2], ans[i - 1][3])) + x[i].a;
			}
			if (b2 <= n / 2) {
				ans[i][2] = max(ans[i - 1][1], max(ans[i - 1][2], ans[i - 1][3])) + x[i].b;
			}
			if (c3 <= n / 2) {
				ans[i][3] = max(ans[i - 1][1], max(ans[i - 1][2], ans[i - 1][3])) + x[i].c;
			}
			if (a1 >= b2 && a1 >= c3)
				a1++;
			else if (b2 >= a1 && b2 >= c3)
				b2++;
			else
				c3++;
			cout << a1 << b2 << c3 << "\n";
			//printf("%d %d %d\n", ans[i][1], ans[i][2], ans[i][3]);
		}
		lans = max(lans, max({ans[n][1], ans[n][2], ans[n][3]}));
		/*sort(x + 1, x + n + 1, cmp2);
		a1 = 0;
		b2 = 0;
		c3 = 0;
		for (int i = 1; i <= n; i++) {
			ans[i][1] = max(ans[i - 1][1], max(ans[i - 1][2], ans[i - 1][3]));
			ans[i][2] = max(ans[i - 1][1], max(ans[i - 1][2], ans[i - 1][3]));
			ans[i][3] = max(ans[i - 1][1], max(ans[i - 1][2], ans[i - 1][3]));
			if (a1 <= n / 2) {
				ans[i][1] = max(ans[i - 1][1], max(ans[i - 1][2], ans[i - 1][3])) + x[i].a;
				a1++;
			}
			if (b2 <= n / 2) {
				ans[i][2] = max(ans[i - 1][1], max(ans[i - 1][2], ans[i - 1][3])) + x[i].b;
				b2++;
			}
			if (c3 <= n / 2) {
				ans[i][3] = max(ans[i - 1][1], max(ans[i - 1][2], ans[i - 1][3])) + x[i].c;
				c3++;
			}
			printf("%d %d %d\n", ans[i][1], ans[i][2], ans[i][3]);
		}
		lans = max(lans, max({ans[n][1], ans[n][2], ans[n][3]}));
		sort(x + 1, x + n + 1, cmp3);
		a1 = 0;
		b2 = 0;
		c3 = 0;
		for (int i = 1; i <= n; i++) {
			ans[i][1] = max(ans[i - 1][1], max(ans[i - 1][2], ans[i - 1][3]));
			ans[i][2] = max(ans[i - 1][1], max(ans[i - 1][2], ans[i - 1][3]));
			ans[i][3] = max(ans[i - 1][1], max(ans[i - 1][2], ans[i - 1][3]));
			if (a1 <= n / 2) {
				ans[i][1] = max(ans[i - 1][1], max(ans[i - 1][2], ans[i - 1][3])) + x[i].a;
				a1++;
			}
			if (b2 <= n / 2) {
				ans[i][2] = max(ans[i - 1][1], max(ans[i - 1][2], ans[i - 1][3])) + x[i].b;
				b2++;
			}
			if (c3 <= n / 2) {
				ans[i][3] = max(ans[i - 1][1], max(ans[i - 1][2], ans[i - 1][3])) + x[i].c;
				c3++;
			}
			printf("%d %d %d\n", ans[i][1], ans[i][2], ans[i][3]);
		}
		lans = max(lans, max({ans[n][1], ans[n][2], ans[n][3]}));*/
		cout << lans << "\n";
	}
	return 0;
}
