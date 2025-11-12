#include <bits/stdc++.h>
using namespace std;

struct club {
	int a, b, c;
};

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int maxn = -10;
		club p[20005];
		int sum = 0;
		int a1 = 0, b1 = 0, c1 = 0;
		for (int i = 0; i < n; i++) {
			cin >> p[i].a >> p[i].b >> p[i].c;
			if (a1 <= n / 2 && b1 <= n / 2 && c1 <= n / 2) {
				maxn = max(p[i].a, max(p[i].b, p[i].c));
				if (maxn == p[i].a) {
					a1++;
				} else if (maxn == p[i].b) {
					b1++;
				} else
					c1++;
				sum += maxn;
			}
		}
		cout << sum << endl;

	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}