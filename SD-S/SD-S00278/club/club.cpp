#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int r, n, res = 0, maxn = INT_MIN, w;
int q[N][5], ans[5], t[N], a[N][5], dt1[N], dt2[N];

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &r);
	while (r -- ){
		res = 0;
		memset(ans, 0, sizeof ans);
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++ ){
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
			q[i][1] = a[i][1], q[i][2] = a[i][2], q[i][3] = a[i][3];
			stable_sort(q[i] + 1, q[i] + 4);
			if (q[i][3] == a[i][3]){
				ans[3] ++ ;
			}else if (q[i][3] == a[i][2]){
				ans[2] ++ ;
			}else{
				ans[1] ++ ;
			}
			res += q[i][3];
		}
		int v = 0;
		for (int i = 1; i <= 3; i ++ ){
			if (ans[i] > n / 2) v ++ ;
		}
		int len1 = 0, len2 = 0;
		if (v == 1){
			for (int i = 1; i <= 3; i ++ ){
				if (ans[i] > n / 2){
					for (int j = 1; j <= n; j ++ ){
						if (q[j][3] == a[j][i]){  
							int l1, l2;
							if (i == 1){
								l1 = 2;l2 = 3;
							}else if (i == 2){
								l1 = 1;l2 = 3;
							}else{
								l1 = 1;l2 = 2;
							}
							int db = a[j][i] - a[j][l1], dc = a[j][i] - a[j][l2];
							if (db > dc){
								res -= dc;
								ans[l2] ++ ;
								ans[i] -- ;
								if (ans[l2] > n / 2){
									res += dc;
									ans[l2] -- ;
									ans[i] ++ ;
									res -= db;
									ans[l1] ++ ;
									ans[i] -- ;
								}
							}else{
								res -= db;
								ans[l1] ++ ;
								ans[i] -- ;
								if (ans[l1] > n / 2){
									res += db;
									ans[l1] -- ;
									ans[i] ++ ;
									res -= dc;
									ans[l2] ++ ;
									ans[i] -- ;
								}
							}
							if (ans[i] <= n / 2) break;
						}
					}
					break;
				}
			}
		}else if (v == 2){
			for (int i = 1; i <= 3; i ++ ){
				if (ans[i] <= n / 2){
					int l1, l2;
					if (i == 1){
						l1 = 2;l2 = 3;
					}else if (i == 2){
						l1 = 1;l2 = 3;
					}else{
						l1 = 1;l2 = 2;
					}
					for (int j = 1; j <= n; j ++ ){
						dt1[j] = a[j][l1] - a[j][i];
						dt2[j] = a[j][l2] - a[j][i];
					}
					stable_sort(dt1 + 1, dt1 + n + 1);
					stable_sort(dt2 + 1, dt2 + n + 1);
					int al1 = ans[l1], al2 = ans[l2];
					for (int j = 1; j <= al1 - n / 2; j ++ ){
						res -= dt1[j];
						ans[i] ++ ;
						ans[l1] -- ;
					}
					for (int j = 1; j <= al2 - n / 2; j ++ ){
						res -= dt2[j];
						ans[i] ++ ;
						ans[l2] -- ;
					}
					break;
				}
			}
		}
		cout << res << "\n";
	}
	return 0;
}
