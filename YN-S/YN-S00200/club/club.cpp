#include <bits/stdc++.h>
using namespace std;

struct st {
	int a;
	int b;
	int c;
	int num;
};
st d[100005];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n, ans = 0, tmp = 0, a1 = 0, b1 = 0, c1 = 0;
	cin >> t;
	while (t != 0) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> d[i].a >> d[i].b >> d[i].c;
			tmp = max(d[i].a, d[i].b);
			d[i].num = max(d[i].c, tmp);
			if (d[i].num == d[i].a)
				a1++;
			else if (d[i].num == d[i].b)
				b1++;
			else if (d[i].num == d[i].c)
				c1++;

			if (a1 <= n / 2 && b1 <= n / 2 && c1 <= n / 2) {
				ans = ans + d[i].num;
			}
		}
		t--;
	}
	cout << ans;
	return 0;
}