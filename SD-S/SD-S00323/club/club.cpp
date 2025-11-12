#include<bits/stdc++.h>
#define endl '\n'
#define rep(A, B, C) for(int (A) = (B); (A) <= (C); A++)
#define dwn(A, B, C) for(int (A) = (B); (A) >= (C); A--)
#define debug "-------------"
using namespace std;
const int INF = 0x3f3f3f3f; 
const int N = 200 + 5;
const int M = 1e5 + 5;
int a[M][5];
int dp[N][N / 2][N / 2][N / 2];
int n; 
int b[M];
bool cmp(int x, int y){
	return x > y;
}
void solve2(){
	rep(i, 1, n) b[i] = a[i][1];
	sort(b + 1, b + 1 + n, cmp);
	int ans = 0;
	for(int i = 1; i <= n / 2; i++){
		ans += b[i];
	}
	cout << ans << endl;
}
void solve(){
	memset(dp, 0, sizeof(dp));
	cin >> n;
	bool A = 1;
	rep(i, 1, n){
		cin >> a[i][1] >> a[i][2] >> a[i][3]; 
		if(a[i][2] || a[i][3]) A = 0;
	}
	if(A){
		solve2(); 
		return;
	}
	rep(i, 1, n){
		rep(c1, 0, i){
			if(c1 > n / 2) break;
			rep(c2, 0, i - c1){
				if(c2 > n / 2) break;
				rep(c3, 0, i - c1 - c2){
					if(c3 > n / 2) break;
					if(c1 + c2 + c3 != i){
						dp[i][c1][c2][c3] = -INF;continue;
					} 
					if(c1 > 0) dp[i][c1][c2][c3] = max(dp[i][c1][c2][c3], dp[i - 1][c1 - 1][c2][c3] + a[i][1]);
					if(c2 > 0) dp[i][c1][c2][c3] = max(dp[i][c1][c2][c3], dp[i - 1][c1][c2 - 1][c3] + a[i][2]);
					if(c3 > 0) dp[i][c1][c2][c3] = max(dp[i][c1][c2][c3], dp[i - 1][c1][c2][c3 - 1] + a[i][3]);
				}
			}
		}
	}
	int ans = 0;
	rep(c1, 0, n / 2){
		if(c1 > n / 2) break;
		rep(c2, 0, n - c1){
			if(c2 > n / 2) break;
			rep(c3, 0, n - c2 - c1){
				if(c3 > n / 2) break;
				if(c1 + c2 + c3 != n){
					continue;
				} 
				ans = max(ans, dp[n][c1][c2][c3]);
			}
		}
	}
	cout << ans << endl;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t_;
	cin >> t_;
	while(t_--){
		solve(); 
	} 
	return 0;
}
