#include<bits/stdc++.h>
using namespace std;
int n, a[100005][4];
int main(){
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int T;
	cin >> T;
	while (T--){
		cin >> n;
		int A = 1, B = 1;
		for (int i = 1; i <= n; i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][2]!=0) A = 0;
			if (a[i][3]!=0) B = 0;
		}
		if (n == 2){
			int t = a[1][1]+a[2][2];
			t = max(t, a[1][1]+a[2][3]);
			t = max(t, a[1][2]+a[2][1]);
			t = max(t, a[1][2]+a[2][3]);
			t = max(t, a[1][3]+a[2][1]);
			t = max(t, a[1][3]+a[2][2]);
			cout << t << endl;
			continue;
		}
		if (n == 4){
			int t = 0, cf[4] = {0};
			for (int i = 1; i <= 3; i++){
				cf[i]++;
				for (int j = 1; j <= 3; j++){
					cf[j]++;
					if(cf[j]>2){
						cf[i]--;
						continue;
					}
					for (int ii = 1; ii <= 3; ii++){
						cf[ii]++;
						if(cf[ii]>2){
							cf[ii]--;
							continue;
						}
						for (int jj = 1; jj <= 3; jj++){
							cf[jj]++;
							if(cf[jj]>2){
								cf[jj]--;
								continue;
							}
							t = max(t, a[1][i]+a[2][j]+a[3][ii]+a[4][jj]);
							cf[jj]--;
						}
						cf[ii]--;
					}
					cf[j]--;
				}
				cf[i]--;
			}
			cout << t << endl;
			continue;
		}
		if (n == 10){
			int t = 0, cf[11]= {0};
			for (int i1 = 1; i1 <= 3; i1++){
				cf[i1]++;
				for (int i2 = 1; i2 <= 3; i2++){
					cf[i2]++;
					if(cf[i2]>5){
						cf[i2]--;
						continue;
					}
					for (int i3 = 1; i3 <= 3; i3++){
						cf[i3]++;
						if(cf[i3]>5){
							cf[i3]--;
							continue;
						}
						for (int i4 = 1; i4 <= 3; i4++){
							cf[i4]++;
							if(cf[i4]>5){
								cf[i4]--;
								continue;
							}
							for (int i5 = 1; i5 <= 3; i5++){
								cf[i5]++;
								if(cf[i5]>5){
									cf[i5]--;
									continue;
								}
								for (int i6 = 1; i6 <= 3; i6++){
									cf[i6]++;
									if(cf[i6]>5){
										cf[i6]--;
										continue;
									}
									for (int i7 = 1; i7 <= 3; i7++){
										cf[i7]++;
										if(cf[i7]>5){
											cf[i7]--;
											continue;
										}
										for (int i8 = 1; i8 <= 3; i8++){
											cf[i8]++;
											if(cf[i8]>5){
												cf[i8]--;
												continue;
											}
											for (int i9 = 1; i9 <= 3; i9++){
												cf[i9]++;
												if(cf[i9]>5){
													cf[i9]--;
													continue;
												}
												for (int i10 = 1; i10 <= 3; i10++){
													cf[i10]++;
													if(cf[i10]>5){
														cf[i10]--;
														continue;
													}
													t = max(t, a[1][i1]+a[2][i2]+a[3][i3]+a[4][i4]+a[5][i5]+a[6][i6]+a[7][i7]+a[8][i8]+a[9][i9]+a[10][i10]);
													cf[i10]--;
												}
												cf[i9]--;
											}
											cf[i8]--;
										}
										cf[i7]--;
									}
									cf[i6]--;
								}
								cf[i5]--;
							}
							cf[i4]--;
						}
						cf[i3]--;
					}
					cf[i2]--;
				}
				cf[i1]--;
			}
			cout << t << endl;
			continue;
		}
		if (A){
			int vis[100005] = {0}, t = 0;
			for (int i = 1; i <= n/2; i++){
				int mx = 0;
				for (int j = 1; j <= n; j++){
					if(a[j][1]>mx and !vis[j]){
						mx = a[j][1];
						vis[j] = 1;
					}
				}
				t += mx;
			}
			cout << t << endl;
			continue;
		}
		if (B){
			int vis[100005] = {0}, t = 0;
			for (int i = 1; i <= n/2; i++){
				int mx = 0;
				for (int j = 1; j <= n; j++){
					if(a[j][1]>mx and !vis[j]){
						mx = a[j][1];
						vis[j] = 1;
					}
				}
				t += mx;
			}
			cout << t << endl;
			continue;
		}
		cout << endl;
	}
	return 0;
}

//AH!CCF!!!i love you
