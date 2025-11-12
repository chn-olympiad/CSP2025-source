#include <bits/stdc++.h> 
#define rep(i, a, b) for(int i = a; i <= b; i++) 
#define per(i, a, b) for(int i = a; i >= b; i--)
#define IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0); 
#define int long long 
#define endl "\n" 
#define lc(i) i << 1ll 
#define rc(i) i << 1ll | 1ll
const int N = 5000 + 7;
const int mod = 998244353; 
int a[N]; 
int n; 
int ans = 0; 
bool vis[N]; 
void dfs(int step, int sum, int max, int cnt) {
	if(step + 1 == n) {
		if(sum > 2 * max && cnt >= 3) {
			ans++; 
			ans %= mod; 
		}
		return ; 
	}
	
	rep(i, 1, n) {
		if(vis[i] == true) continue; 
		bool flag = false; 
		vis[i] = true;
		dfs(step + 1, sum + a[i], std::max(max, a[i]), ++cnt); 
		vis[i] = false; 
	}
}

int fact[N]; 

int A(int n, int m) {
	return fact[m] / fact[n] % mod;
}

int dp[N][N];

void solve() { 
	std::cin >> n; 
	bool flag = true; 
	rep(i, 1, n) {
		std::cin >> a[i];
		if(a[i] > 1) flag = false;  
	}
	fact[0] = fact[1] = 1;
	rep(i, 2, n) {
		fact[i] = fact[i - 1] * i; 
		fact[i] %= mod; 
	} 
	if(n <= 3) { // 12 pts
		std::sort(a + 1, a + 1 + n); 
		if(a[1] + a[2] > a[3]) {
			std::cout << 1 << endl; 
		} else {
			std::cout << 0 << endl; 
		}
		return ; 
	}
	
	if(flag) { // 24 pts
		int res = 0; 
		rep(i, 3, n) {
			res += A(i, n); 
			res %= mod; 
		}
		std::cout << res % mod << endl; 
	
		return ; 
	}
	if(n <= 10) { // 12 pts
		dfs(1, 0, 0, 0); 
		std::cout << ans / 2 % mod << endl;  // qu chong chu yi 2
		return ;
	}
	
	rep(i, 1, n) dp[i][i] = 1; 
	
	
	rep(i, 1, n) {
		rep(j, i + 1, n) {
			dp[i][j] += a[i]; 
			dp[i][j] %= mod; 
			dp[i + 1][j - 1] = std::max(dp[i + 1][j - 1], dp[i][j]);
			dp[i + 1][j - 1] %= mod; 
			if(dp[i][j] > 2 * dp[i + 1][j - 1])  {
				dp[i + 1][j - 1] += dp[i][j]; 
				dp[i + 1][j - 1] %= mod; 
			}
		}
	}
	
	int ans = 0; 
	rep(i, 1, n) {
		ans += dp[i][i];
		ans %= mod;  
	}
	std::cout << ans << endl; 
	
}
signed main() {
	freopen("polygon.in", "r", stdin); 
	freopen("polygon.out", "w", stdout); 
	IOS; 
	solve();
	return 0;  
}

/*
3 3
94 95 96 97 98 99 100 93 92
2 2
99 100 97 98
让 m >= 3 个数构成的子序列 的子序列和大于 二倍的子序列最大值 
*/
