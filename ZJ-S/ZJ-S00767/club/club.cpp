#include <bits/stdc++.h>
#define int long long
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define N 250
using namespace std;

struct p{
	int x;
	int y;
	int z;
}a[N];

int t, n, ans;
int f2, f3;
int dp[N][N][N];

int cmp1(p a, p b){
	return a.x > b.x;
}
int cmp2(p a, p b){
	return abs(a.x - a.y) > abs(b.x - b.y);
}

signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t --){
		memset(dp, 0, sizeof(dp));
		ans = 0;
		cin >> n;
		f2 = 1;
		f3 = 1;
		for(int i = 1;i <= n;i ++){
			cin >> a[i].x >> a[i].y >> a[i].z;
			if(a[i].y) f2 = 0;
			if(a[i].z) f3 = 0;
		}
		if(f2 && f3){
			sort(a + 1, a + n + 1, cmp1);
			for(int i = 1;i <= n / 2;i ++) ans += a[i].x;
			cout << ans << endl;
			continue;
		}
		if(f3){
			sort(a + 1, a + n + 1, cmp2);
			int l = 0, r = 0;
			for(int i = 1;i <= n;i ++){
				if(l == n / 2){
					ans += a[i].y;
					r ++;
				}else if(r == n / 2){
					ans += a[i].x;
					l ++;
				}else if(a[i].x > a[i].y){
					ans += a[i].x;
					l ++;
				}else{
					ans += a[i].y;
					r ++;
				}
			}
			cout << ans << endl;
			continue;
		}
		for(int i = 0;i <= n / 2;i ++){
			for(int j = 0;j <= n / 2;j ++){
				for(int k = 0;k <= min((n - i - j), n / 2);k ++){
					if(!i && !j && !k){
						dp[i][j][k] = 0;
					}else{
						if(i) dp[i][j][k] = max(dp[i - 1][j][k] + a[i + j + k].x, dp[i][j][k]);
						if(j) dp[i][j][k] = max(dp[i][j - 1][k] + a[i + j + k].y, dp[i][j][k]);
						if(k) dp[i][j][k] = max(dp[i][j][k - 1] + a[i + j + k].z, dp[i][j][k]);
					}
					if(i + j + k == n) ans = max(ans, dp[i][j][k]);
				}
			}
		}
//		for(int i = 0;i <= n / 2;i ++){
//			for(int j = 0;j <= n / 2;j ++){
//				for(int k = 0;k <= n / 2;k ++){
//					cout << "dp[" << i << "][" << j << "][" << k << "]:" << dp[i][j][k] << " ";
//				}
//				cout << endl;
//			}
//			cout << "--------------" << endl;
//		}
		cout << ans << endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
