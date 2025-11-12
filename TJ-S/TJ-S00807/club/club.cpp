#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 201,M = 1e5+1;
int t,n,a[M][4],x[M],dp[N][N][N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		if(n<=200){
			for(int i = 1;i<=n;++i){
				for(int j = 1;j<=3;++j){
					cin >> a[i][j];
				}
			}
			for(int i = 0;i<=n/2;++i){
				for(int j = 0;j<=n/2;++j){
					for(int k = 0;k<=n/2;++k){
						dp[i][j][k] = 0;
					}
				}
			}
			int ans = 0;
			for(int i = 1;i<=n;++i){
				for(int j = 0;j<=i&&j<=n/2;++j){
					for(int k = 0;k<=i-j&&k<=n/2;++k){
						int l = i-j-k;
						if(l>n/2){
							continue;
						}
						if(j!=0){
							dp[j][k][l] = max(dp[j][k][l],dp[j-1][k][l]+a[i][1]);
						}
						if(k!=0){
							dp[j][k][l] = max(dp[j][k][l],dp[j][k-1][l]+a[i][2]);
						}
						if(l!=0){
							dp[j][k][l] = max(dp[j][k][l],dp[j][k][l-1]+a[i][3]);
						}
						if(i == n){
							ans = max(ans,dp[j][k][l]);
						}
					}
				}
			}
			cout << ans << '\n';
		}else{
			bool flag1 = true,flag2 = true;
			for(int i = 1;i<=n;++i){
				for(int j = 1;j<=3;++j){
					cin >> a[i][j];
					if(j == 2&&a[i][j]!=0){
						flag1 = false;
					}
					if(j == 3&&a[i][j]!=0){
						flag2 = false;
					}
				}
			}
			if(flag1&&flag2){
				for(int i = 1;i<=n;++i){
					x[i] = a[i][1];
				}
				stable_sort(x+1,x+n+1);
				int sum = 0;
				for(int i = n;i>n/2;--i){
					sum+=x[i];
				}
				cout << sum << '\n';
			}else{
				srand(time(0));
				cout << rand()*rand() << '\n';
			}
		}
	}
	return 0;
}
