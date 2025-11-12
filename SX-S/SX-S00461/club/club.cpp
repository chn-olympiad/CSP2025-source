#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
long long int t;
long long int mi = 20010,  maxn = 0, minn = 20010, n, sum;
long long int a[100010][5], se[100010], maxx[100010], mini[100010], d[5], flag;
long long int flag_1[100010], flag_2[100010], flag_3[100010];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {

		cin >> n;
		for (long long int i = 1; i <= n; i++) {
			for (long long int j = 1; j <= 3; j++) {
				cin >> a[i][j];
				if (a[i][j] >= maxn) {
					maxn = a[i][j];
					maxx[i] = a[i][j];
					flag_1[i] = j;
				}
				if (a[i][j] < maxn && a[i][j] > minn) {
					se[i] = a[i][j];
				}
				if (a[i][j] <= minn) {
					minn = a[i][j];
					mini[i] = a[i][j];
					flag_3[i] = j;
				}
				if (flag_1[i] != j && flag_3[i] != j) {
					flag_2[i] = j;
				}
			}
		}//输入并找出满意度由大到小的序号及各满意度；
		for (long long int k = 1; k <= n; k++) {
			d[flag_1[k]]++;
			if (d[flag_1[k]] > (n / 2)) {
				d[flag_1[k]]--;
				for (long long int l = 1; l <= k; l++) {
					if (a[l][d[flag_1[k]]] != 0 && a[l][d[flag_1[k]]] <= mi) {
						mi = a[l][d[flag_1[k]]];
						flag = l;
					}
					flag_2[flag]++;
					if (flag_2[flag] > (n / 2)) {
						flag_2[flag]--;
						flag_3[flag]++;
						sum += mini[flag];
					} else {
						sum += se[flag];
					}
				}
			} else {
				sum += maxx[k];
			}
		}
		cout << sum << endl;
		sum = 0;
		maxn = 0;
		minn = 20010;
		mi = 20010;
		memset(d, 0, sizeof(d));
		flag = 0;
		memset(se, 0, sizeof(se));
		memset(maxx, 0, sizeof(maxx));
		memset(mini, 0, sizeof(mini));
		memset(flag_1, 0, sizeof(flag_1));
		memset(flag_2, 0, sizeof(flag_2));
		memset(flag_3, 0, sizeof(flag_3));
	}

	return 0;
}/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0*/