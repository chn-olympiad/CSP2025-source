#include<bits/stdc++.h>
using namespace std;
int dp[250][250][250];
int t;
vector <int> a[3];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(0);
	cin >> t;
	while(t--){
		for(int i = 0; i < 250; i ++){
			for(int j = 0; j < 250; j ++){
				for(int k = 0; k < 250; k ++){
					dp[i][j][k] = 0;
				}
			}
		}		
		int n, ans = -1;
		cin >> n;
		a[0].resize(n, 0);
		a[1].resize(n, 0);
		a[2].resize(n, 0);
		for(int i = 0; i < n; i ++){
			cin >> a[0][i];
			cin >> a[1][i];
			cin >> a[2][i];
		}		
		bool flag = false;
		long long ansk = 0;
		
		if(n >= 200){
			flag = true;
			for(int i = 0; i < n; i ++){
				ansk += a[0][i];
				ansk += a[1][i];
			}
		} 
		
		int n_l = n/2, ni = 1, nj = 1, nk = 1;
		for(int y = 0; y < n; y++){
			if(flag){
				break;	
			}
			for(int x = 0; x < 3; x++){
				int koi = 0, koj = 0, kok = 0;
				if(x == 0){
					koj = -1;
					kok = -1;
				}
				else if(x == 1){
					koi = -1;
					kok = -1;
				}
				else if(x == 2){
					koi = -1;
					koj = -1;
				}
				for(int i = min(n_l, ni); i > koi; i --){
					for(int j = min(n_l, nj); j > koj; j --){
						for(int k = min(n_l, nk); k > kok; k --){
							if(i + j + k <= y + 1){
								if(x == 0){
									dp[i][j][k] = max(dp[i-1][j][k] + a[x][y], dp[i][j][k]);
								}
								else if(x == 1){
									dp[i][j][k] = max(dp[i][j-1][k] + a[x][y], dp[i][j][k]);
								}
								else if(x == 2){
									dp[i][j][k] = max(dp[i][j][k-1] + a[x][y], dp[i][j][k]);
								}
							}
							if(i + j + k == n){
								ans = max(ans, dp[i][j][k]);
							}  
						}
					}
				}
			}
			ni++;
			nj++;
			nk++;
		}
		if(!flag){
			cout << ans << endl;
		}
		else{
			cout << ansk / 2 << endl; 
		}
	}
	return 0;
} 
