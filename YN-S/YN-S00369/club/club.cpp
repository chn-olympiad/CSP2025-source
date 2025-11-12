#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 500;
int  zhao[4], t, sum[N];

struct cluber1 {
	int a;
	int b;
	int c;
	int zhaomu;
	int houxuan;
	int houxuanz;
} cluber[N];

struct zh1 {
	int zh;
	int xh;
} zh[N];

int p(cluber1 a, cluber1 b) {
	return a.houxuanz > b.houxuanz;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;

	for (int i = 1; i <= t; i++) {

		int n;
		cin >> n;

		for (int j = 1; j <= n; j++) {

			cin >> cluber[j].a >> cluber[j].b >> cluber[j].c;
			cluber[j].zhaomu = 0;

			if (cluber[j].a >= cluber[j].c && cluber[j].a >= cluber[j].b) {
				cluber[j].houxuan = 1;
				cluber[j].houxuanz = cluber[j].a;
			}

			if (cluber[j].b >= cluber[j].a && cluber[j].b >= cluber[j].c) {
				cluber[j].houxuan = 2;
				cluber[j].houxuanz = cluber[j].b;
			}

			if (cluber[j].c >= cluber[j].a && cluber[j].a >= cluber[j].b) {
				cluber[j].houxuan = 3;
				cluber[j].houxuanz = cluber[j].c;
			}
		}

		int b = 1;

		for (int j = 1; j <= 3; j++) {

			sort(cluber + 1, cluber + 1 + n, p);


			for (int k = 1; k <= n; k++) {

				if (cluber[k].houxuan == j && zhao[j] <= n / 2 ) {
					sum[i] += cluber[k].houxuanz;
					zhao[j]++;
				} else if (cluber[k].houxuan == j && zhao[j] > n / 2) {
					if (cluber[k].a >= cluber[k].c || cluber[k].a >= cluber[k].b && cluber[k].houxuan != j && zhao[1] < n / 2) {
						sum[i] += cluber[k].a;
					}

					else if (cluber[k].b >= cluber[k].a || cluber[k].b >= cluber[k].c && cluber[k].houxuan != j && zhao[2] < n / 2) {
						sum[i] += cluber[k].b;
					}

					else if (cluber[k].c >= cluber[k].a || cluber[k].a >= cluber[k].b && cluber[k].houxuan != j && zhao[3] < n / 2) {
						sum[i] += cluber[k].c;
					}
				}

			}

		}

	}

	for (int i = 1; i <= t; i++) {

		cout << sum[i] << endl;
	}

	return 0;
}