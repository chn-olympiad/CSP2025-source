#include <bits/stdc++.h>
using namespace std;
int t, n, aa[10010][10010][3], ans[10010], f = 0, b = 0, x = 0, fff[10010];
int ffx[10010], fbf[10010], kma[10010], kmi[10010], kmid[10010], mm1, mm2, mm3;

int max(int a, int ba, int c) {
	int k;
	if (a > ba && a > c)
		k = a;
	else if (ba > c)
		k = ba;
	else
		k = c;
	return k;
}

int min(int d, int e, int fa) {
	int l;
	if (d < e && d < fa)
		l = d;
	else if (e < fa)
		l = e;
	else
		l = fa;
	return l;
}

int secmax(int g, int h, int i) {
	int v;
	if ((g > h && g < i) || (g < h && g > i))
		v = g;
	else if ((h > g && h < i) || (h < g && h > i))
		v = h;
	else
		v = i;
	return v;
}

void fbx() {
	for (int i = 1; i <= t; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 0; k <= 2; ++k) {
				fff[j] = max(aa[i][j][0], aa[i][j][1], aa[i][j][2]);
				ffx[j] = secmax(aa[i][j][0], aa[i][j][1], aa[i][j][2]);
				fbf[j] = min(aa[i][j][0], aa[i][j][1], aa[i][j][2]);
				kma[j] = fff[j] - ffx[j];
				kmi[j] = ffx[j] - fbf[j];
				kmid[j] = fff[j] - fbf[j];
			}
			if (fff[j] == aa[i][j][0])
				f++;
			else if (fff[j] == aa[i][j][1])
				b++;
			else
				x++;
			if ((f / 3) == (n / 2) or (b / 3) == (n / 2) or (x / 3) == (n / 2)) {
				if ((f / 3) == (n / 2)) {
					if ((b / 3) == (n / 2)) {
						for (int s = 1; s <= n; ++s) {
							if (kmid[s] > kmid[s + 1])
								mm3 = kmid[s + 1];
							else
								continue;
						}
						ans[j] += mm1;
						ans[j] += ffx[j];
					} else
						for (int s = 1; s <= n; ++s) {
							if (kma[s] > kma[s + 1])
								mm3 = kma[s + 1];
							else
								continue;
						}
					ans[j] += mm2;
					ans[j] += ffx[j];
				}
				if ((b / 3) == (n / 2) and (x / 3) == (n / 2)) {
					for (int s = 1; s <= n; ++s) {
						if (kmi[s] > kmi[s + 1])
							mm3 = kmi[s + 1];
						else
							continue;
					}
					ans[j] += mm3;
					ans[j] += fbf[j];
				}
			}
		}
	}
}


int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cin >> n;
		for (int j = 1; j <= n; ++j) {
			cin >> aa[i][j][0] >> aa[i][j][1] >> aa[i][j][2];
			fbx();
		}
	}
	for (int i = 1; i <= t; ++i)
		cout << ans[i] / t << endl;
	return 0;
}
