#include <bits/stdc++.h>
using namespace std;
int D1[100005], D2[100005], D3[100005], aa[4], aa2[4], aa3[4], aa4[4], aa5[11][4], judge[5], aa6[100050][2];
int times, num, id, ans, tot1, tot2, now, now2;
bool flag = false;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> times;
	while (times > 0) {
		times--;
		ans = 0;
		cin >> num;
		if (num == 2) {
			for (int i = 1; i <= 3; i++)
				cin >> aa[i];
			for (int i = 1; i <= 3; i++)
				cin >> aa2[i] ;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (i != j)
						ans = max(ans, aa[i] + aa2[j]);
				}
			}
			cout << ans << endl;
		} else if (num == 4) {
			for (int i = 1; i <= 3; i++)
				cin >> aa[i];
			for (int i = 1; i <= 3; i++)
				cin >> aa2[i];
			for (int i = 1; i <= 3; i++)
				cin >> aa3[i];
			for (int i = 1; i <= 3; i++)
				cin >> aa4[i];
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					for (int k = 1; k <= 3; k++) {
						for (int l = 1; l <= 3; l++) {
							if ((i == j == k) || (i == j == l) || (j == k == l ) || (i == k == l) )
								continue;
							else
								ans = max(ans, aa[i] + aa2[j] + aa3[k] + aa4[l]);
						}
					}
				}
			}
			cout << ans << endl;
		} else if (num == 10) {
			for (int i = 1; i <= 10; i++) {
				for (int j = 1; j <= 3; j++) {
					cin >> aa5[i][j];
				}
			}
			for (int q1 = 1; q1 <= 3; q1++) {
				for (int q2 = 1; q2 <= 3; q2++) {
					for (int q3 = 1; q3 <= 3; q3++) {
						for (int q4 = 1; q4 <= 3; q4++) {
							for (int q5 = 1; q5 <= 3; q5++) {
								for (int q6 = 1; q6 <= 3; q6++) {
									for (int q7 = 1; q7 <= 3; q7++) {
										for (int q8 = 1; q8 <= 3; q8++) {
											for (int q9 = 1; q9 <= 3; q9++) {
												for (int q10 = 1; q10 <= 3; q10++) {
													judge[q1]++;
													judge[q2]++;
													judge[q3]++;
													judge[q4]++;
													judge[q5]++;
													judge[q6]++;
													judge[q7]++;
													judge[q8]++;
													judge[q9]++;
													judge[q10]++;
													if (judge[1] <= 5 && judge[2] <= 5 && judge[3] <= 5) {
														judge[1] = judge[2] = judge[3] = 0;
														ans = max(ans, aa5[1][q1] + aa5[2][q2] + aa5[3][q3] + aa5[4][q4] + aa5[5][q5] + aa5[6][q6] + aa5[7][q7] + aa5[8][q8] +
														          aa5[9][q9] + aa5[10][q10]);
													} else
														judge[1] = judge[2] = judge[3] = 0;

												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			cout << ans << endl;
		} else if (num == 200) {
			now = now2 = 0;
			tot1 = tot2 = 0;
			for (int i = 1; i <= num; i++) {
				cin >> D1[i] >> D2[i] >> D3[i];
			}
			for (int i = 1; i <= num; i++) {
				if (D1[i] > D2[i])
					aa6[D1[i] - D2[i]][1]++;
				else
					aa6[D2[i] - D1[i]][2]++;
			}
			for (int i = 1; i <= num; i++) {
				if (D1[i] > D2[i])
					tot1++;
				else
					tot2++;
				if (tot1 <= num / 2 && tot2 <= num / 2)
					ans += max(D1[i], D2[i]);
				else if (tot1 > num / 2) {
					tot1--;
					tot2++;
					int temp1 = D1[i] - D2[i];
					now = 0;
					while (1) {
						if (aa6[now][1] > 0)
							break;
						now++;
					}
					if (temp1 > aa6[now][1]) {
						ans = ans - aa6[now][1] + D1[i];
						aa6[now][1]--;
						aa6[temp1][1]++;
					} else {
						ans += D2[i];
						aa6[temp1][2]++;
					}
				} else if (tot2 > num / 2) {
					tot2--;
					tot1++;
					int temp2 = D2[i] - D1[i];
					now2 = 0;
					while (1) {
						if (aa6[now2][2] > 0)
							break;
						now2++;
					}
					if (temp2 > aa6[now2][2]) {
						ans = ans - aa6[now2][2] + D2[i];
						aa6[now2][2]--;
						aa6[temp2][2]++;
					} else {
						ans += D1[i];
						aa6[temp2][1]++;
					}
				}
			}
			cout << ans << endl;
		}
		if (num >= 500) {
			for (int i = 1; i <= num; i++) {
				cin >> D1[i] >> D2[i] >> D3[i];
				if (D2[i] != 0)
					flag = true;
			}
			if (flag == false) {
				sort(D1 + 1, D1 + num + 1);
				for (int i = num; i > num / 2; i--)
					ans += D1[i];
				cout << ans << endl;
			} else if (flag == true) {
				now = now2 = 0;
				tot1 = tot2 = 0;
				for (int i = 1; i <= num; i++) {
					cin >> D1[i] >> D2[i] >> D3[i];
				}
				for (int i = 1; i <= num; i++) {
					if (D1[i] > D2[i])
						aa6[D1[i] - D2[i]][1]++;
					else
						aa6[D2[i] - D1[i]][2]++;
				}
				for (int i = 1; i <= num; i++) {
					if (D1[i] > D2[i])
						tot1++;
					else
						tot2++;
					if (tot1 <= num / 2 && tot2 <= num / 2)
						ans += max(D1[i], D2[i]);
					else if (tot1 > num / 2) {
						tot1--;
						tot2++;
						int temp1 = D1[i] - D2[i];
						while (1) {
							if (aa6[now][1] > 0)
								break;
							now++;
						}
						if (temp1 > aa6[now][1]) {
							ans = ans - aa6[now][1] + D1[i];
							aa6[now][1]--;
							aa6[temp1][1]++;
						} else {
							ans += D2[i];
							aa6[temp1][2]++;
						}
					} else if (tot2 > num / 2) {
						tot2--;
						tot1++;
						int temp2 = D2[i] - D1[i];
						while (1) {
							if (aa6[now2][2] > 0)
								break;
							now2++;
						}
						if (temp2 > aa6[now2][2]) {
							ans = ans - aa6[now2][2] + D2[i];
							aa6[now2][2]--;
							aa6[temp2][2]++;
						} else {
							ans += D1[i];
							aa6[temp2][1]++;
						}
					}
				}
				cout << ans << endl;
			}
		}
	}
	return 0;
}
