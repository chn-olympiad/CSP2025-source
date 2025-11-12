#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int a1[100005], a2[100005], a3[100005];
int zai1, zai2, zai3, ans1, ans2, ans3, ans;
int cha1[100005], cixiao[100005], cha2[100005], cha3[100005];
int zaii1[100005], zaii2[100005], zaii3[100005];//¶¨Î»
int tot1, tot2, tot3;
int flag;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		zai1 = 0;
		zai2 = 0;
		zai3 = 0;
		ans1 = 0;
		ans2 = 0;
		ans3 = 0;
		flag = 0;
		memset(a1, 0, sizeof(a1));
		memset(a2, 0, sizeof(a2));
		memset(a3, 0, sizeof(a3));
		scanf("%d", &n);
		m = n / 2;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a1[i], &a2[i], &a3[i]);
			if (a3[i] == 0)
				flag++;
			if (a1[i] > a2[i] && a1[i] > a3[i]) {
				zai1++;
				zaii1[zai1] = i;
				ans1 += a1[i];
				if (a2[i] > a3[i]) {
					cha1[zai1] = a1[i] - a2[i];
					cixiao[i] = 2;
				} else {
					cha1[zai1] = a1[i] - a3[i];
					cixiao[i] = 3;
				}
			}
			if (a2[i] > a1[i] && a2[i] > a3[i]) {
				zai2++;
				zaii2[zai2] = i;
				ans2 += a2[i];
				if (a1[i] > a3[i]) {
					cha2[zai1] = a2[i] - a1[i];
					cixiao[i] = 1;
				} else {
					cha2[zai1] = a2[i] - a3[i];
					cixiao[i] = 3;
				}
			}
			if (a3[i] > a1[i] && a3[i] > a2[i]) {
				zai3++;
				zaii3[zai3] = i;
				ans3 += a3[i];
				if (a1[i] > a2[i]) {
					cha3[zai1] = a3[i] - a1[i];
					cixiao[i] = 2;
				} else {
					cha3[zai1] = a3[i] - a2[i];
					cixiao[i] = 3;
				}
			}
		}
		ans = ans1 + ans2 + ans3;
		if (flag == n) {
			if (zai1 > zai2) {
				sort(cha1 + 1, cha1 + 1 + n);
				for (int i = 1; i <= zai1; i++) {
					if (cha1[i] == 0) {
						zai1++;
						continue;
					}
					zai2++;
					ans -= cha1[i];
					if (zai2 == m)
						break;
				}
			} else {
				sort(cha2 + 1, cha2 + 1 + n);
				for (int i = 1; i <= zai2; i++) {
					if (cha2[i] == 0) {
						zai2++;
						continue;
					}
					zai1++;
					ans -= cha2[i];
					if (zai1 == m) {
						break;
					}
				}
			}
			printf("%d", ans);
			return 0;
		}
		if (zai1 <= m && zai2 <= m && zai3 <= m)
			printf("%d", ans);
		else {
			while (zai1 > m || zai2 > m || zai3 > m) {
				if (zai1 > n / 2) {
					sort(cha1 + 1, cha1 + 1 + n);
					for (int i = 1; i <= zai1; i++) {
						ans -= cha1[zaii1[i]];
						//	cout << cixiao[zaii1[zai1]] << endl;
						if (cixiao[zaii1[i]] == 2) {
							zai2++;

							cixiao[zaii1[i]] = 3;
							cha2[zai2] = a2[zaii1[i]] - a3[zaii1[i]];
						} else {
							zai3++;
							cixiao[zaii1[i]] = 2;
							cha3[zai3] = a3[zaii1[i]] - a2[zaii1[i]];
						}
						zai1--;
						if (zai1 <= m)
							break;
					}
				}
				if (zai2 > n / 2) {
					sort(cha2 + 1, cha2 + 1 + n);
					for (int i = 1; i <= zai2; i++) {
						ans -= cha2[zaii2[i]];
						if (cixiao[zaii2[i]] == 1) {
							zai1++;
							cixiao[zaii1[i]] = 3;
							cha1[zai1] = a1[zaii2[i]] - a3[zaii2[i]];
						} else {
							zai3++;
							cixiao[zaii1[zai3]] = 1;
							cha3[zai3] = a3[zaii2[i]] - a1[zaii2[i]];
						}
						zai2--;
						if (zai2 <= m)
							break;
					}
				}
				if (zai3 > n / 2) {
					for (int i = 1; i <= zai3; i++) {
						ans -= cha3[zaii3[i]];
						if (cixiao[zaii3[i]] == 1) {
							zai1++;
							cixiao[zaii1[i]] = 2;
							cha1[zai1] = a1[zaii3[i]] - a2[zaii3[i]];
						} else {
							zai3++;
							cixiao[zaii2[i]] = 1;
							cha2[i] = a2[zaii3[i]] - a1[zaii3[i]];
						}
						zai3--;
						if (zai3 <= m)
							break;
					}
				}
			}
			printf("%d", ans);
		}
		cout << endl;
	}
	return 0;
}
/*1
4
1 100 0
2 100 0
3 100 0
4 100 0*/