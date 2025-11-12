#include <bits/stdc++.h>
using namespace std;
int n, p[4];

struct node {
	int a[4];
	int b[4];
	int h;
	int m;
} d[114514];

bool cmp(node x, node y) {
	return x.m > y.m ;
}

void lll() {
	for (int i = 1; i <= n; i++) {

		if (d[i].b[1] >= d[i].b[2] && d[i].b[1] >= d[i].b[3] ) {
			if (d[i].b[1] == d[i].b[2] && d[i].b[1] > d[i].b[3]) {
				if (p[1] < p[2])
					d[i].h = 1;
				else
					d[i].h = 2;
			} else if (d[i].b[1] == d[i].b[3] && d[i].b[1] > d[i].b[2]) {
				if (p[1] < p[3])
					d[i].h = 1;
				else
					d[i].h = 3;
			} else if (d[i].b[1] == d[i].b[2] && d[i].b[1] == d[i].b[3]) {
				if (p[1] < p[2] && p[1] < p[3])
					d[i].h = 1;
				else if (p[2] < p[1] && p[2] < p[3])
					d[i].h = 2;
				else
					d[i].h = 3;
			} else
				d[i].h = 1;
			d[i].m = d[i].b[1];
			continue;
		}

		if (d[i].b[2] >= d[i].b[1] && d[i].b[2] >= d[i].b[3] ) {
			if (d[i].b[3] == d[i].b[2]) {
				if (p[3] < p[2])
					d[i].h = 3;
				else
					d[i].h = 2;
			} else
				d[i].h = 2;
			d[i].m = d[i].b[2];
			continue;
		}

		if (d[i].b[3] >= d[i].b[2] && d[i].b[3] >= d[i].b[1] ) {
			d[i].h = 3;
			d[i].m = d[i].b[3];
			continue;
		}
	}

	return;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int yyswys;
	cin >> yyswys;

	while (yyswys--) {
		cin >> n;
		int ans = 0;
		p[1] = 0;
		p[2] = 0;
		p[3] = 0;

		for (int i = 1; i <= n; i++) {

			cin >> d[i].a[1] >> d[i].a[2] >> d[i].a[3] ;
			d[i].b [1] = d[i].a[1] - (d[i].a[2] + d[i].a[3]);
			d[i].b [2] = d[i].a[2] - (d[i].a[1] + d[i].a[3]);
			d[i].b [3] = d[i].a[3] - (d[i].a[2] + d[i].a[1]);

		}

		lll();
		sort(d + 1, d + 1 + n, cmp);

//		cout << endl;
//		for (int i = 1; i <= n; i++) {
//
//			cout << d[i].a[1] << " " << d[i].a[2] << " " << d[i].a[3] << endl;
//		}
//
//		cout << endl;
//
//		for (int i = 1; i <= n; i++) {
//
//			cout << d[i].b[1] << " " << d[i].b[2] << " " << d[i].b [3] << endl;
//		}

//		for (int i = 1; i <= n; i++) {
//
//			cout << d[i].h << endl;
//		}

		for (int i = 1; i <= n; i++) {

			p[d[i].h ]++;
			ans += d[i].a [d[i].h ];
//			cout << d[i].a [d[i].h ] << endl;

//			for (int u = 1; u <= n; u++) {
//
//				cout << endl << d[u].b[1] << " " << d[u].b[2] << " " << d[u].b [3] << " " << d[u].h << endl ;
//			}

			if (p[1] == n / 2) {
				for (int j = i + 1; j <= n; j++) {

					d[j].b [1] = -11451419;
				}

				p[1]++;
				lll();
				sort(d + 1 + i, d  + 1 + n, cmp);
			}

			if (p[2] == n / 2) {
				for (int j = i + 1; j <= n; j++) {

					d[j].b [2] = -11451419;
				}

				p[2]++;
				lll();
				sort(d + 1 + i, d + 1 + n, cmp);
			}

			if (p[3] == n / 2) {
				for (int j = 1 + i; j <= n; j++) {

					d[j].b [3] = -11451419;
				}

				p[3]++;
				lll();
				sort(d + 1 + i, d  + 1 + n, cmp);
			}
		}

		cout << ans << endl;
	}

	return 0;
}
