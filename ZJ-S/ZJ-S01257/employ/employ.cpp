#include <bits/stdc++.h>
using namespace std;
const int N = 510;
const int mod = 998244353;
long long dp[N][N][N];
bool tf[N];
int num[N];
int qzh[N];
int read(){
	int s = 0;
	char ch = getchar();
	while(ch > '9' || ch < '0'){
		ch = getchar();
	}
	while(ch <= '9' && ch >= '0'){
		s = (s << 3) + (s << 1) + (ch ^ 48);
		ch = getchar();
	}
	return s;
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	char ch = getchar();
	for(int i = 1; i <= n; i++){
		tf[i] = getchar();
	}
	for(int i = 1; i <= n; i++){
		num[i] = read();
		qzh[num[i]]++;
	}
	for(int i = 1; i <= n; i++){
		qzh[i] += qzh[i - 1];
	}
	dp[0][0][0] = 1;
	for(int i = 1; i <= n; i++){
		if(tf[i] == 1){
			for(int j = 0; j < i; j++){
				for(int k = 0; k <= j; k++){
					dp[i][j][k] += dp[i - 1][j][k] * (n - i + 1 - qzh[j] + k - j) % mod;
				}
			}
			for(int j = 1; j <= i; j++){
				for(int k = 1; k <= j; k++){
					dp[i][j][k] += dp[i - 1][j - 1][k - 1] * (qzh[j] - k) % mod;
				}
			}
		}
		else{
			for(int j = 1; j < i; j++){
				for(int k = 0; k <= j; k++){
					dp[i][j][k] += dp[i - 1][j - 1][k] * (n - i + 1 - qzh[j] + k - j) % mod;
				}
			}
			for(int j = 1; j < i; j++){
				for(int k = 1; k <= j; k++){
					dp[i][j][k] += dp[i - 1][j - 1][k - 1] * (qzh[j] - k) % mod;
				}
			}
		}
	}
	/*for(int i = 1; i <= n; i++){
		for(int j = 0; j <= i; j++){
			for(int k = 0; k <= j; k++){
				cout << dp[i][j][k] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}*/
	long long ans = 0;
	for(int i = 1; i <= n - m; i++){
		for(int j = 0; j <= i; j++){
			ans = (ans + dp[n][i][j]) % mod;
		}
	}
	cout << ans;
	return 0;
}