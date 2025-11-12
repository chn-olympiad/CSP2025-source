#include <bits/stdc++.h>
using namespace std;
int t;
int a[100010][4]; //第i个同学对三个社团的满意值
int am[100010][4]; //第i个同学对三个社团的满意排名
int r[4] ; //加入每个社团的人数
int my ;
int n;

bool isc() {
	if (r[1] <= n / 2 && r[2] <= n / 2 && r[3] <= n / 2)
		return true;
	return false;
}

void gg() {
	if (r[1] > n / 2) {
		int maxx = 21000;
		int jh;
		for (int i = 1; i <= n; i++) {
			if (am[i][1] == 1) {
				if (maxx > a[i][am[i][1]] - a[i][am[i][2]]) {
					maxx = a[i][am[i][1]] - a[i][am[i][2]];
					jh = i;
				}
			}
		}
		my -= maxx;
		r[am[jh][2]] ++;
		r[1] --;
		int jh2 = a[jh][1];
		a[jh][1] = a[jh][am[jh][2]];
		a[jh][am[jh][2]] = a[jh][am[jh][3]];
		a[jh][am[jh][3]] = jh2;
		am[jh][1] = am[jh][2];
		am[jh][2] = am[jh][3];
		am[jh][3] = 1;
	}
	if (r[2] > n / 2) {
		int maxx = 21000;
		int jh;

		for (int i = 1; i <= n; i++) {
			if (am[i][1] == 2) {
				if (maxx > a[i][am[i][1]] - a[i][am[i][2]]) {
					maxx = a[i][am[i][1]] - a[i][am[i][2]];
					jh = i;

				}
			}
		}
		my -= maxx;
		r[am[jh][2]] ++;
		r[2] --;
		int jh2 = a[jh][2];
		a[jh][2] = a[jh][am[jh][2]];
		a[jh][am[jh][2]] = a[jh][am[jh][3]];
		a[jh][am[jh][3]] = jh2;
		am[jh][1] = am[jh][2];
		am[jh][2] = am[jh][3];
		am[jh][3] = 2;
	}
	if (r[3] > n / 2) {
		int maxx = 21000;
		int jh;
		for (int i = 1; i <= n; i++) {
			if (am[i][1] == 3) {
				if (maxx > a[i][am[i][1]] - a[i][am[i][2]]) {
					maxx = a[i][am[i][1]] - a[i][am[i][2]];
					jh = i;
				}
			}
		}
		my -= maxx;
		r[am[jh][2]] ++;
		r[3] --;
		int jh2 = a[jh][3];
		a[jh][3] = a[jh][am[jh][2]];
		a[jh][am[jh][2]] = a[jh][am[jh][3]];
		a[jh][am[jh][3]] = jh2;
		am[jh][1] = am[jh][2];
		am[jh][2] = am[jh][3];
		am[jh][3] = 3;
	}
	if (isc())
		return;
	else
		gg();
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	int myans[t + 3];
	int T = t;
	while (t >= 1) {
		my = 0;
		r[1] = 0;
		r[2] = 0;
		r[3] = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][1] >= a[i][2] && a[i][2] >= a[i][3]) {
				am[i][1] = 1;
				am[i][2] = 2;
				am[i][3] = 3;
			} else if (a[i][1] >= a[i][3] && a[i][3] >= a[i][2]) {
				am[i][1] = 1;
				am[i][2] = 3;
				am[i][3] = 2;
			} else if (a[i][2] >= a[i][1] && a[i][1] >= a[i][3]) {
				am[i][1] = 2;
				am[i][2] = 1;
				am[i][3] = 3;
			} else if (a[i][2] >= a[i][3] && a[i][3] >= a[i][1]) {
				am[i][1] = 2;
				am[i][2] = 3;
				am[i][3] = 1;
			} else if (a[i][3] >= a[i][1] && a[i][1] >= a[i][2]) {
				am[i][1] = 3;
				am[i][2] = 1;
				am[i][3] = 2;
			} else if (a[i][3] >= a[i][2] && a[i][2] >= a[i][1]) {
				am[i][1] = 3;
				am[i][2] = 2;
				am[i][3] = 1;
			}
			r[am[i][1]]++;
			my += a[i][am[i][1]];
		}

		if (isc())
			myans[t] = my;
		else {
			gg();
			myans[t] = my;
		}
		t--;
	}
	for (int i = T ; i >= 1; i--) {
		cout << myans[i] << endl;
	}
	return 0;
}
