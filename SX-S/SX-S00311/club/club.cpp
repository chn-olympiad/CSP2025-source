#include <bits/stdc++.h>
using namespace std;

struct node {
	int num, nn;
} a[100005], b[100005], c[100005];

bool cmp(node x, node y) {
	return x.num > y.num;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for (int u = 1; u <= t; u++) {
		int n;
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> a[j].num >> b[j].num >> c[j].num;
			a[j].nn = j;
			b[j].nn = j;
			c[j].nn = j;
		}
		sort(a + 1, a + n + 1, cmp);
		sort(b + 1, b + n + 1, cmp);
		sort(c + 1, c + n + 1, cmp);
		bool s = 0;
		int sum = 0, o = n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					if (a[i].nn != b[j].nn  && a[i].nn != c[k].nn
					        && b[j].nn != c[k].nn ) {
						if (o < n) {
							if (o == 2) {
								sum += max(a[i].num + b[j].num, max(b[j].num + c[k].num, a[i].num + c[k].num));
								s = 1;
							} else {
								sum = sum + max(a[i].num, max(b[j].num, c[k].num));
								s = 1;
							}
						}
						if (s == 1)
							break;
						sum += a[i].num + b[j].num + c[k].num;
						o -= 3;
					}
				}
				if (s == 1)
					break;
			}
			if (s == 1)
				break;
		}
		cout << sum << endl;
	}

	return 0;
}