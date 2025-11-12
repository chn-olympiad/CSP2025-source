#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m, a[505];
string str;

int cnt[(1 << 18) + 5];
int dp[2][(1 << 18) + 5][20];

void Add(int &x, int y){
	x += y;
	if(x >= mod) x -= mod;
}
void solve(){
	for(int i = 0; i < (1 << 18); i++){
		for(int j = 0; j < 18; j++){
			cnt[i] += (((i >> j)) % 2);
		} 
	}
	
	dp[0][0][0] = 1;
	for(int i = 0; i < n; i++){
		for(int S = 0; S < (1 << n); S++){
			for(int j = 0; j <= (i - 1); j++){
				dp[((i & 1) ^ 1)][S][j] = 0;
			}
		}
		for(int S = 0; S < (1 << n); S++){
			if(cnt[S] == i){
				for(int j = 0; j <= i; j++){
					if(dp[(i & 1)][S][j]) {
						if(str[i + 1] == '0'){
							for(int k = 1; k <= n; k++){
								if(!((S >> (k - 1)) & 1)){
									Add(dp[((i & 1) ^ 1)][(S | (1 << (k - 1)))][j + 1], dp[(i & 1)][S][j]);
								}
							}
						} else {
							for(int k = 1; k <= n; k++){
								if(!((S >> (k - 1)) & 1)){
									if(a[k] <= j){
										Add(dp[((i & 1) ^ 1)][(S | (1 << (k - 1)))][j + 1], dp[(i & 1)][S][j]);
									} else {
										Add(dp[((i & 1) ^ 1)][(S | (1 << (k - 1)))][j], dp[(i & 1)][S][j]);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	int sum = 0;
	for(int i = 0; i <= n - m; i++) Add(sum, dp[(n & 1)][(1 << n) - 1][i]);
	cout << sum << endl;
}

bool check(){
	for(int i = 1; i <= n; i++){
		if(str[i] != '1') return 0;
	}
	for(int i = 1; i <= n; i++) if(a[i] == 0) return 0;
	return 1;
}

void Solve(){
	cout << 0 << endl;
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> str;
	str = " "+ str;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	
	if(n <= 18){
		solve();
	} else {
		if(n == m && !check()){
			cout << "0\n";
			return 0;
		}
		long long ans = 1;
		for(int i = 1; i <= n; i++) (ans *= i) %= mod;
		cout << ans << endl;
	}
	return 0;
}
