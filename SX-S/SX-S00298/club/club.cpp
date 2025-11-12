#include <bits/stdc++.h>
using namespace std;

struct fp {
	int my, k;
};

int cmp(fp y, fp r) {
	return y.my > r.my;
}

int fr[5] = {};
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int n, s = 0, t;
	fp a[5];
	cin >> t;
	for (int i = 1; i <= t; i++) {
		s = 0;
		for (int j = 1; j <= 5; j++)
			fr[j] = 0;
		cin >> n;
		for (int q = 1; q <= n; q++) {
			cin >> a[1].my >> a[2].my >> a[3].my;
			a[1].k = 1;
			a[2].k = 2;
			a[3].k = 3;
			sort(a + 1, a + 1 + n, cmp);
			if (fr[a[1].k] < (n / 2)) {
				s += a[1].my;
				fr[a[1].k] += 1;
				cout << s << endl;
			} else if (fr[a[2].k] < (n / 2)) {
				s += a[2].my;
				fr[a[2].k] += 1;
				cout << s << endl;
			} else {
				s += a[3].my;
				fr[a[3].k] += 1;
				cout << s << endl;
			}
		}
		cout << s << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}