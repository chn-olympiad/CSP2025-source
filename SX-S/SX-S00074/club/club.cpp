#include <bits/stdc++.h>
using namespace std;

int t;

bool check(int x,int n) {
	if (x > n) {
		return true;
	}
	return false;
}

int main () {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	int n;
	int r[10005][4] = {};
	int compeo[4][10005] = {0};
	for (int i = 1;i <= t;i++) {
		cin >> n;
		int cnt = 0;
		for (int j = 1;j <= n;j++) {
			cin >> r[j][1] >> r[j][2] >> r[j][3];
		}
// 赋值输入部分

		int peo = n / 2; //半人

		int acnt[5] = {0,0,0,0,0};
		for (int j = 1;j <= n;j++) {
			int tmp = 0;

			tmp = max(max(r[j][1],r[j][2]),max(r[j][2],r[j][3])); // 已分配部门的愉悦值

			if (tmp == r[j][1]) {
				compeo[1][j] = 1;
				compeo[2][j] = tmp;
				acnt[1]++;

				for (int k = 1;k <= 3;k++) {
					if (check(acnt[1],peo)) {
						acnt[1]--;
						tmp = max(r[j][2],r[j][3]);
						cnt += tmp;
						if (tmp = r[j][2]) {
							compeo[1][j] = 2;
							compeo[2][j] = tmp;
							acnt[2]++;
						}
						if (tmp = r[j][3]) {
							compeo[1][j] = 3;
							compeo[2][j] = tmp;
							acnt[3]++;
						}
						break;
					}
				}
			}

			else if (tmp == r[j][2]) {
				compeo[1][j] = 2;
				compeo[2][j] = tmp;
				acnt[2]++;

				for (int k = 1;k <= 3;k++) {
					if (check(acnt[2],peo)) {
						acnt[2]--;
						tmp = max(r[j][1],r[j][3]);
						cnt += tmp;

						if (tmp = r[j][1]) {
							compeo[1][j] = 1;
							compeo[2][j] = tmp;
							acnt[1]++;
						}
						if (tmp = r[j][3]) {
							compeo[1][j] = 3;
							compeo[2][j] = tmp;
							acnt[3]++;
						}
						break;

					}
    			}
			}

			else if (tmp == r[j][3]) {
				compeo[1][j] = 3;
				compeo[2][j] = tmp;
				acnt[3]++;

				for (int k = 1;k <= 3;k++) {
					if (check(acnt[3],peo)) {
						acnt[3]--;
						tmp = max(r[j][1],r[j][2]);
						cnt += tmp;
						if (tmp = r[j][1]) {
							compeo[1][j] = 1;
							compeo[2][j] = tmp;
							acnt[1]++;
						}
						if (tmp = r[j][2]) {
							compeo[1][j] = 2;
							compeo[2][j] = tmp;
							acnt[2]++;
						}
						break;
					}
				}
			}
			cnt += tmp;
		}


		for (int k = 1;k <= n;k++) {
			if (n >= k) {
				k = n;
			}
		}

		for (int j = 1; j <= n;j++) {
			cout << compeo[1][j] << " " << compeo[2][j] << endl;
		}
		cout << endl;

		cout << cnt << endl;
	}
	return 0;
}
