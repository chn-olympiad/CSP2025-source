/*********************************************************************
    不要忘记取消注释
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;

struct satis {
	int c1;
	int c2;
	int c3;
	long long dlt;
	int wh;
} a[100001];

void fkccf() {
	int n;
	cin >> n;
	long long ans = 0, a1 = 0, a2 = 0, a3 = 0;
	int s[3];

	for (int i = 0; i < n; i++) {

		cin >> a[i].c1 >> a[i].c2 >> a[i].c3;
		s[0] = a[i].c1;
		s[1] = a[i].c2;
		s[2] = a[i].c3;
		sort(s, s + 3);

		if (s[2] == a[i].c1) {
			ans = ans + a[i].c1;
			a1++;
			a[i].wh = 1;
			a[i].dlt = s[2] - s[1];
		} else {
			if (s[2] == a[i].c2) {
				ans = ans + a[i].c2;
				a2++;
				a[i].wh = 2;
				a[i].dlt = s[2] - s[1];
			} else {
				if (s[2] == a[i].c3) {
					ans = ans + a[i].c3;
					a3++;
					a[i].wh = 3;
					a[i].dlt = s[2] - s[1];
				}
			}

		}


	}

	int lim = (n / 2);
	int b[n];
	int x = 0;

	if (a1 > lim) {
		for (int i = 0; i < n; i++) {

			if (a[i].wh == 1) {
				b[x] = a[i].dlt;
				x++;
			}
		}

		sort(b, b + x);

		for (int i = 0; i < (x - lim); i++) {

			ans = ans - b[i];
		}
	}

	if (a2 > lim) {
		for (int i = 0; i < n; i++) {

			if (a[i].wh == 2) {
				b[x] = a[i].dlt;
				x++;
			}
		}

		sort(b, b + x);

		for (int i = 0; i < (x - lim); i++) {

			ans = ans - b[i];
		}
	}

	if (a3 > lim) {
		for (int i = 0; i < n; i++) {

			if (a[i].wh == 3) {
				b[x] = a[i].dlt;
				x++;
			}
		}

		sort(b, b + x);

		for (int i = 0; i < (x - lim); i++) {

			ans = ans - b[i];
		}
	}

	cout << ans << endl;
	return;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;

	for (int v = 0; v < t; v++) {

		fkccf();
	}

//这题诗人？？？
	return 0;
}

