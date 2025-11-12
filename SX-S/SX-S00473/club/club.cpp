#include <bits/stdc++.h>
using namespace std;
int f[100005][5];
long long club1[5];
long long ans;

struct student {
	int a, b, c, id;
	int cha1, cha2, good;
} xue[100005];

bool cmp(student x, student y) {
	if (x.a != y.a) {
		return x.a > y.a;
	} else {
		if (x.cha1 != y.cha1)
			return x.cha1 < y.cha1;
		else
			return x.id > y.id;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int ceshi;
	cin >> ceshi;
	while (ceshi--) {
		int n;
		cin >> n;
		ans = 0;
		memset(f, 0, sizeof(f));
		memset(club1, 0, sizeof(club1));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> f[i][j];
				xue[i].id = i;
			}
			if (f[i][1] >= f[i][2] && f[i][2] >= f[i][3]) {
				xue[i].a = 1;
				xue[i].b = 2;
				xue[i].c = 3;
			} else {
				if (f[i][1] >= f[i][3] && f[i][3] >= f[i][2]) {
					xue[i].a = 1;
					xue[i].b = 3;
					xue[i].c = 2;
				} else {
					if (f[i][2] >= f[i][1] && f[i][1] >= f[i][3]) {
						xue[i].a = 2;
						xue[i].b = 1;
						xue[i].c = 3;
					} else {
						if (f[i][2] >= f[i][3] && f[i][3] >= f[i][1]) {
							xue[i].a = 2;
							xue[i].b = 3;
							xue[i].c = 1;
						} else {
							if (f[i][3] >= f[i][1] && f[i][1] >= f[i][2]) {
								xue[i].a = 3;
								xue[i].b = 1;
								xue[i].c = 2;
							} else {
								if (f[i][3] >= f[i][2] && f[i][2] >= f[i][1]) {
									xue[i].a = 3;
									xue[i].b = 2;
									xue[i].c = 2;
								}
							}
						}
					}
				}
			}
			xue[i].good = xue[i].a;
			club1[xue[i].a]++;
			xue[i].cha1 = f[i][xue[i].a] - f[i][xue[i].b];
			xue[i].cha2 = f[i][xue[i].b] - f[i][xue[i].c];
		}
		sort(xue + 1, xue + 1 + n, cmp);
		bool flag = 0;
		int chao;
		for (int i = 1; i <= 3; i++)
			if (club1[i] > n / 2) {
				flag = 1;
				chao = i;
			}
		if (flag) {
			if (club1[1] != 0 && club1[2] != 0 && club1[3] == 0) {
				if (chao == 1) {
					for (int i = club1[2] + 1; i <= club1[1] + club1[2] - n / 2; i++) {
						xue[i].good = xue[i].b;
					}
				} else {
					if (chao == 2) {
						for (int i = 1; i <= club1[2] - n / 2; i++) {
							xue[i].good = xue[i].b;
						}
					}
				}
			} else if (club1[1] != 0 && club1[2] == 0 && club1[3] == 0) {
				if (chao == 1) {
					for (int i = 1; i <= club1[1] - n / 2; i++) {
						xue[i].good = xue[i].b;
					}
				}
			} else {
				if (chao == 1) {
					for (int i = club1[2] + 1; i <= club1[1] - n / 2; i++) {
						xue[i].good = xue[i].b;
					}
				} else {
					if (chao == 2) {
						for (int i = club1[3] + 1; i <= club1[2] - n / 2; i++) {
							xue[i].good = xue[i].b;
						}
					} else {
						if (chao == 3) {
							for (int i = 1; i <= club1[3] - n / 2; i++) {
								xue[i].good = xue[i].b;
							}
						}
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			ans += f[xue[i].id][xue[i].good];
		}
		cout << ans << endl;
		continue;
	}
	return 0;
}
