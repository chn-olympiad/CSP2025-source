#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int t, n, sumx, sumy, sumz, ans;
int a[N][5], b[N];
int vis[5];

int main(){
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t --){
		ans = 0;
		cin >> n;
		bool flgy = false, flgz = false;
		for (int i = 1; i <= n; i ++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][2] != 0) flgy = true;
			if (a[i][3] != 0) flgz = true;
			sumx += a[i][1];
			sumy += a[i][2];
			sumz += a[i][3];
		}
		if (n == 2){
			for (int i = 1; i <= 3; i ++){
				for (int j = 1; j <= 3; j ++){
					if (i != j){
						ans = max(ans, a[1][i] + a[2][j]);
					}
				}
			}
			cout << ans << '\n';
		}
		else if (n == 4){
			bool f = false;
			for (int i = 1; i <= 3; i ++){
				for (int j = 1; j <= 3; j ++){
					for (int k = 1; k <= 3; k ++){
						for (int l = 1; l <= 3; l ++){
							vis[1] = vis[2] = vis[3] = 0;
							f = false;
							vis[i] ++;
							vis[j] ++;
							vis[l] ++;
							vis[k] ++;
							for (int m = 1; m <= 3; m ++){
								if (vis[m] > 2) f = true;
							}
							if (!f){
								ans = max(ans, a[1][i] + a[2][j] + a[3][k] + a[4][l]);
							}
						}
					}
				}
			}
			cout << ans << '\n';
		}
		else if (n == 10){
			bool f = false;
			for (int i = 1; i <= 3; i ++){
				for (int ii = 1; ii <= 3; ii ++){
					for (int j = 1; j <= 3; j ++){
						for (int jj = 1; jj <= 3; jj ++){
							for (int k = 1; k <= 3; k ++){
								for (int kk = 1; kk <= 3; kk ++){
									for (int l = 1; l <= 3; l ++){
										for (int ll = 1; ll <= 3; ll ++){
											for (int e = 1; e <= 3; e ++){
												for (int ee = 1; ee <= 3; ee ++){
													vis[1] = vis[2] = vis[3] = 0;
													f = false;
													vis[i] ++; vis[ii] ++;
													vis[j] ++; vis[jj] ++;
													vis[k] ++; vis[kk] ++;
													vis[l] ++; vis[ll] ++;
													vis[e] ++; vis[ee] ++;
													for (int m = 1; m <= 3; m ++){
														if (vis[m] > 5) f = true;
													}
													if (!f){
														int cnt=a[1][i]+a[2][ii]+a[3][j]+a[4][jj]+a[5][k]+a[6][kk]+a[7][l]+a[8][ll]+a[9][e]+a[10][ee];
														ans = max(ans, cnt);
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
			}
			cout << ans << '\n';
		}
		else if(!flgy && !flgz){
			for (int i = 1; i <= n; i ++){
				b[i] = a[i][1];
			}
			sort(b + 1, b + n + 1);
			for (int i = n; i > n / 2; i --){
				ans += b[i];
			}
			cout << ans << '\n';
		}
	}
	
	return 0;
}
