#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, i;
	cin >> t;
	int renshu[t + 1] = {0};
	int zuida[t + 1] = {0};
	for (i = 1; i <= t; i++ ) {
		cin >> renshu[i];
		zuida[i] = renshu[i] / 2;
	}

	for (i = 1; i <= t; i++ ) {
		int rensh = renshu[i];
		int sum = 0; //满意度总和
		int bumenrenshu[4] = {0};
		int c[rensh + 1] = {0};
		int benfen[rensh + 1][3] = {0};

		for (int j = 1; j <= renshu[i]; j++ ) {//这组数据开始
			int a[4] = {0};
			int b[4] = {0};

			for (int k = 1; k <= 3; k++) {
				cin >> a[k];
				b[k] = a[k];
			}
			b[4] = max(a[1], a[2]);
			b[5] = max(a[3], a[2]);
			a[1] = max(b[4], b[5]);
			a[2] = min(b[4], b[5]);
			c[j] = a[1] - a[2];
			benfen[j][1] = a[1];
			benfen[j][2] = a[2];
		}
		int caozuo = 0;

		while (zuida[i] > caozuo ) {
			int max = 0;
			int cun, j;
			for (j = 1; j <= renshu[i]; j++ ) {
				if (c[j] >= max) {
					max = c[j];
					cun = j;
				}
			}
			sum += benfen[cun][1];
			c[cun] = 0;
			benfen[cun][2] = 0;
			caozuo += 1;
		}

		for (int j = 1; j <= renshu[i]; j++ ) {
			sum += benfen[j][2];
		}

		cout << sum << endl;
	}
	return 0;
}