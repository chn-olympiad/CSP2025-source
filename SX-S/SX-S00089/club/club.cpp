#include <bits/stdc++.h>
using namespace std;

struct club {
	int s, nu;
} pl[100005];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t = 0;
	cin >> t;
	while (t--) {
		int n = 0, ans = 0, sl[4] = {0}, m = 0, suml, su = 0;
		club p[100000];
		cin >> suml;
		suml = 3 * n;
		for (int i = 1; i <= suml; i++) {
			cin >> pl[i].s;
			if (i % 3 == 1) {
				pl[i].nu = 1;
			} else if (i % 3 == 2) {
				pl[i].nu = 2;
			} else if (i % 3 == 0) {
				pl[i].nu = 3;
			}
			p[i] = pl[i];
		}
		for (int i = 1; i <= suml; i++) {
			int sum = 1;
			for (int j =  1; j <= suml; j++) {
				if (pl[sum].s < pl[j].s) {
					swap(pl[sum], pl[j]);
					sum = j;
				}
			}
			m = i;
			for (int j = 1; j <= suml - i; j++) {
				pl[j] = p[m + 1];
				m++;
			}
		}
		for (int i = 1; i <= suml; i++) {
			cout << pl[i].s << " ";
		}
		for (int i = 1;; i++) {
			sl[pl[i].nu]++;
			if (sl[1] > n / 2 || sl[2] > n / 2 || sl[3] > n / 2)
				continue;
			ans = pl[i].s + ans;
			su++;
			if (su == n)
				break;

		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


