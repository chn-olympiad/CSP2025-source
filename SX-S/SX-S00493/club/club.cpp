#include <bits/stdc++.h>
using namespace std;
int t, n, a[100005][3], s = 0;
int club1 = 0, club2 = 0, club3 = 0;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
			}
		}
		if (n == 2) {
			club1 = max(a[1][1], a[2][1]);
			club2 = max(a[1][2], a[2][2]);
			club3 = max(a[1][3], a[2][3]);
			if (club3 >= club1 && club2 >= club1) {
				s += club3;
				s += club2;
			} else if (club2 >= club3 && club1 >= club3) {
				s += club1;
				s += club2;
			} else if (club1 >= club2 && club3 >= club2) {
				s += club3;
				s += club1;
			}
			cout << s;
		} else {
			for (int i = 1; i <= n; i++) {
				for (int j = i; j <= n; j++) {
					if (a[i][1] < a[j][1]) {
						int q = a[i][1];
						a[i][1] = a[j][1];
						a[j][1] = q;
					}
				}
			}
			for (int i = 1; i <= n / 2; i++) {
				club1 += a[i][1];
			}
			s = club1;
			cout << s;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}