#include <bits/stdc++.h>
using namespace std;
int  l;
int a[10005];
int c[10005];
int d[10005];
int e[10005];
//int flag[10005];
//long long b[10005][10005];
int gs[5];

struct pj {
	int pm;
	int gs2;
	int biaoji = 0;
	int se;
	int third;
} flag[10005];

int cmp(int n, int m) {
	return n > m;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> l;
	for (int i = 1; i <= l; i++) {
		cin >> a[i];
		int sum = 0;
		int renshu = a[i] / 2;
		for (int j = 1; j <= a[i]; j++) {
			cin >> c[j] >> d[j] >> e[j];
			if (c[j] > d[j] && c[j] > e[j]) {
				//int ans = c[j];
				flag[j].pm = c[j];
				flag[j].gs2 = 1;
				if (d[j] > e[j]) {
					flag[j].se = d[j];
					flag[j].third = e[j];
				} else {
					flag[j].se = e[j];
					flag[j].third = d[i];
				}

			} else if (d[j] > c[j] && d[j] > e[j]) {
				flag[j].pm = d[j];
				flag[j].gs2 = 2;
				if (c[j] > e[j]) {
					flag[j].se = c[j];
					flag[j].third = e[j];
				} else {
					flag[j].se = e[j];
					flag[j].third = c[i];
				}
			} else if (e[j] > c[j] && e[j] > d[j]) {
				flag[j].pm = e[j];
				flag[j].gs2 = 3;
				if (c[j] > d[j]) {
					flag[j].se = c[j];
					flag[j].third = d[j];
				} else {
					flag[j].se = c[j];
					flag[j].third = d[i];
				}
			}
		}//∫·œÚ≈≈–Ú

		sort(c + 1, c + a[i] + 1, cmp);
		sort(d + 1, d + a[i] + 1, cmp);
		sort(e + 1, e + a[i] + 1, cmp);

//		for (int j = 1; j <= a[i]; j++) {
		//	cout << c[j] << " " << d[j] << " " << e[j] << endl;
		//}
		//cout << renshu << endl;
		for (int k = 1; k <= renshu; k++) {

			for (int x = 1; x <= a[i]; x++) {
				if (c[k] == flag[x].pm && flag[x].biaoji != -1) {
					flag[x].biaoji = -1;
					sum += c[k];
				} else if (d[k] == flag[x].pm && flag[x].biaoji != -1) {
					flag[x].biaoji = -1;
					sum += d[k];
				} else if (e[k] == flag[x].pm && flag[x].biaoji != -1) {
					flag[x].biaoji = -1;
					sum += e[k];
				}
			}
		}
		//cout << c[k] << " " << d[k] << " " << e[k] << endl;
		/* for (int x = 1;  x <= a[i]; x++){

			if (c[k] == flag[x].pm && flag[x].biaoji != -1) {
				sum += c[k];
				cout << sum << " " << c[k] << endl;
				flag[x].biaoji = -1;
				gs[1]++;
				//flag3 == 1;
				continue;
			}


			else if (d[k] == flag[x].pm && flag[x].biaoji != -1) {
				sum += c[k];
				flag[x].biaoji = -1;
				gs[2]++;
				cout << sum << " " << c[k] << endl;
				continue;
			} else if (e[k] == flag[x].pm && flag[x].biaoji != -1) {
				sum += c[k];
				flag[x].biaoji = -1;
				gs[3]++;
				cout << sum << " " << c[k] << endl;
				continue;
			}
		}
		}*/
		/*for (int k = 1; k <= a[i]; k++) {
			if (flag[k].biaoji != -1) {
				if (gs[1] < renshu) {
					for (int x = 1; x <= renshu; x++) {
						if (flag[k].se == c[x])
							sum += flag[k].se;
						else if (flag[k].third == c[x])
							sum += flag[k].third;
					}
				} else if (gs[2] < renshu) {
					for (int x = 1; x <= renshu; x++) {
						if (flag[k].se == d[x])
							sum += flag[k].se;
						else if (flag[k].third == d[x])
							sum += flag[k].third;
					}
				} else if (gs[3] < renshu) {
					for (int x = 1; x <= renshu; x++) {
						if (flag[k].se == e[x])
							sum += flag[k].se;
						else if (flag[k].third == e[x])
							sum += flag[k].third;
					}
				}

			}
		}*/
		cout << sum;
	}
	return 0;

}
