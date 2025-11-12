#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;

int n;
int a[N][10]; // 1, 2, 3; 4: max(2, 3);
int cnt[10];

namespace bf{
	
const int N = 200 + 2;

int dp[N][N][N];

void solve(){
	for(int i = 1; i <= n; i ++){
		cin >> a[i][1] >> a[i][2] >> a[i][3];
	}
	memset(dp, 0, sizeof dp);
	int ans = 0;
	for(int i = 1; i <= n; i ++){
		for(int j = 0; j <= i; j ++){
			for(int k = 0; k <= i - j; k ++){
				if(j > (n >> 1))  continue;
				if(k > (n >> 1))  continue;
				if(i - j - k > (n >> 1))  continue;
				if(j > 0)  dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + a[i][1]);
				if(k > 0)  dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + a[i][2]);
				if(i > j + k)  dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + a[i][3]);
				ans = max(ans, dp[i][j][k]);
//				cerr << i << ' ' << j << ' ' << k << ' ' << i - j - k << ' ' << dp[i][j][k] << '\n';
			}
		}
	}
	cout << ans << '\n';
//	cerr << '\n';
}

}

namespace sub1{	

int idx[N];

void solve(){
	int ans = 0;
	for(int i = 1; i <= n; i ++){
		idx[i] = i;
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		ans += a[i][1];
		a[i][2] -= a[i][1];
	}
	sort(idx + 1, idx + n + 1, [](int x, int y){
		return a[x][2] > a[y][2];
	});
	for(int i = 1; i <= (n >> 1); i ++)  ans += a[idx[i]][2];
	cout << ans << '\n';
}

}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;  cin >> T;
	while(T --){
		cin >> n;
		if(n <= 200)
			bf::solve();
		else
			sub1::solve();
	}
	
	return 0;
}