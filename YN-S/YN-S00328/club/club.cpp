#include <bits/stdc++.h>
using namespace std;
int x[1005][4], s1, s2, s3, g1, g2, g3, ju1[1005], ju2[1005], ju3[1005], zzz;
int max1, max2, max3;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> zzz;
	while (zzz--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x[i][1] >> x[i][2] >> x[i][3];
			if (x[i][1] >= x[i][2] && x[i][1] >= x[i][3]) {
				x[i][0] = 1;
			}
			if (x[i][2] >= x[i][1] && x[i][2] >= x[i][3]) {
				x[i][0] = 2;
			}
			if (x[i][3] >= x[i][2] && x[i][3] >= x[i][1]) {
				x[i][0] = 3;
			}
		}
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n; j++) {
				if (x[j][0] == 1 && x[j][1] > x[max1][1])
					max1 = j;
				if (x[j][0] == 2 && x[j][2] > x[max2][2])
					max2 = j;
				if (x[j][0] == 3 && x[j][3] > x[max3][3])
					max3 = j;
			}
			if (g1 <= n / 2 && x[max1][0] != 0) {
				s1 += x[max1][1];
				x[max1][0] = 0;
				ju1[g1] = max1;
				g1++;
			}
			if (g2 <= n / 2 && x[max2][0] != 0) {
				s2 += x[max2][2];
				x[max2][0] = 0;
				ju1[g2] = max2;
				g2++;
			}
			if (g3 <= n / 2 && x[max3][0] != 0) {
				s3 += x[max3][3];
				x[max3][0] = 0;
				ju1[g3] = max3;
				g3++;
			}
			max1 = max2 = max3 = 0;
		}
		for (int i = 0; i < n ; i++) {
			if (x[i][0] != 0) {
				if (x[i][0] == 1) {
					for (int j = 0; j < g1; j++) {
						if (x[ju1[j]][2] > x[ju1[j]][3]) {
							if (x[ju1[j]][2] > x[i][2] && g2 <= n / 2) {
								g2++;
								s1 -= x[ju1[j]][1];
								s1 += x[i][1];
								s2 += x[ju1[j]][2];
							} else {
								if (x[ju1[j]][3] > x[i][3] && g3 <= n / 2) {
									g3++;
									s1 -= x[ju1[j]][1];
									s1 += x[i][1];
									s3 += x[ju1[j]][3];
								} else {
									if (x[i][2] > x[i][3]) {
										g2++;
										s2 += x[i][2];
									} else {
										g3++;
										s3 += x[i][3];
									}
								}
							}
						}
					}
				}
				if (x[i][0] == 2) {
					for (int j = 0; j < g2; j++) {
						if (x[ju2[j]][1] > x[ju2[j]][3]) {
							if (x[ju2[j]][1] > x[i][1] && g1 <= n / 2) {
								g1++;
								s2 -= x[ju2[j]][1];
								s2 += x[i][1];
								s1 += x[ju2[j]][2];
							} else {
								if (x[ju2[j]][3] > x[i][3] && g3 <= n / 2) {
									g3++;
									s2 -= x[ju2[j]][1];
									s2 += x[i][1];
									s3 += x[ju2[j]][3];
								} else {
									if (x[i][1] > x[i][3]) {
										g1++;
										s1 += x[i][1];
									} else {
										g3++;
										s3 += x[i][3];
									}
								}
							}
						}
					}
				}
				if (x[i][0] == 3) {
					for (int j = 0; j < g3; j++) {
						if (x[ju3[j]][2] > x[ju3[j]][1]) {
							if (x[ju3[j]][2] > x[i][2] && g2 <= n / 2) {
								g2++;
								s3 -= x[ju3[j]][3];
								s3 += x[i][3];
								s2 += x[ju3[j]][2];
							} else {
								if (x[ju3[j]][1] > x[i][1] && g1 <= n / 2) {
									g1++;
									s3 -= x[ju3[j]][3];
									s3 += x[i][3];
									s1 += x[ju3[j]][1];
								} else {
									if (x[i][2] > x[i][3]) {
										g2++;
										s2 += x[i][2];
									} else {
										g1++;
										s1 += x[i][1];
									}
								}
							}
						}
					}
				}
			}
		}
		cout << s1 + s2 + s3;
	}
	return 0;
}