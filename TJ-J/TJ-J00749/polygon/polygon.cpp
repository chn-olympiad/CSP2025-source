#include<iostream>
#include<algorithm>
using namespace std;
const int MOD = 998244353;
int n;
long long a[5001], f[5001][5001], ans;
long long two[5001];
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	two[0] = 1;
	for(int i = 1; i <= n; i++) {
		two[i] = two[i-1] * 2 % MOD;
	}
	f[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= 5000; j++) {
			f[i][j] = f[i-1][j];
			if(j - a[i] >= 0) {
				f[i][j] += f[i-1][j-a[i]];
			}
			f[i][j] %= MOD;
		}
	}
	for(int i = 3; i <= n; i++) {
	       ans = (ans + two[i-1]) % MOD;
	       for(int j = 0; j <= a[i]; j++) {
		       ans = (ans - f[i-1][j] + MOD) % MOD;
	       }
	}
	cout << ans << endl;
	return 0;
}
