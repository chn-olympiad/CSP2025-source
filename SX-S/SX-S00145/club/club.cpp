#include <bits/stdc++.h>
using namespace std;
int n, t, a1, a2, a3, best, c1 = 0, c2 = 0, c3 = 0, sum = 0;

bool tool(int a, int b) {
	if (a > b)
		return 1;
	else
		return 0;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int x = 0; x < t; x++) {
		cin >> n;
		sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a1 >> a2 >> a3;
			if (c1 == n / 2) {
				best = max(a2, a3);
				sum += best;
			} else if (c2 == n / 2) {
				best = max(a1, a3);
				sum += best;
			} else if (c3 == n / 2) {
				best = max(a1, a2);
				sum += best;
			} else {
				best = max(a1, max(a2, a3));
				sum += best;
				if (best == a1)
					c1++;
				else if (best == a2)
					c2++;
				else
					c3++;
			}
		}
		cout << sum << endl;
	}
}
