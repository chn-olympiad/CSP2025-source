/*
kitto todoku hazu
kitto mieru hazu
sonna atte metai mirai wo
boku ha hitorikiri no sekai de
zutto sou uta utatte ita
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
const int N = 5e3+5;

int n, a[N], pw[N];
int c[N][N], mx = 0, mn = 514114;

namespace subtask1{
	int ans = 0;
	
	void dfs(int x, int sm, int mx){
		if(x == n+1)return ans = (ans + (sm > 2*mx ? 1 : 0)) % mod , void();
		
		dfs(x+1, sm, mx);
		dfs(x+1, sm+a[x], max(mx, a[x]));
	}
	
	int main(){
		dfs(1, 0, 0);
		cout<<ans;
	}
}

namespace subtask2{
	int main(){
		int ans = 0;
		for(int i = 3; i <= n; i++)ans = (ans + c[n+1][i]) % mod;
		cout<<ans;
	}
}

namespace subtask3{
	int ps[N], ct[N];
	int dp[N*N];
	int main(){
		for(int i = 1; i <= n; i++)a[i] -= mn;mx -= mn;
		for(int i = 1; i <= n; i++)ct[a[i]]++;
		for(int i = 1; i <= mx; i++)ps[i] = (ps[i-1]+ct[i]) % mod;;
		
		dp[a[1]] = 1;
		for(int i = 2; i <= n; i++){
			for(int j = mx*mx; j >= a[i]; j--){
				dp[j] = (dp[j] + dp[j-a[i]]) % mod;
			}
		}
		int ans = 0;
		for(int i = 0; i <= mx; i++){
			ans += dp[i];
		}
		cout<<ans;
	}
}

signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	for(int i = 1; i <= 5001; i++){
		c[i][0] = 1;
		for(int j = 1; j < i; j++){
			c[i][j] = (c[i-1][j-1]+c[i-1][j]) % mod;
		}
	}
//	for(int i = 1; i <= 10; i++){
//		for(int j = 0; j < i; j++)cout<<c[i][j]<<" \n"[j == i-1];
//	}
	
	cin>>n;
	int fg = 1;
	for(int i = 1; i <= n; i++)cin>>a[i], fg = (a[i] > 1 ? 0 : fg), mx = max(mx, a[i]), mn = min(mn, a[i]);
	if(n <= 20)subtask1 :: main(); //40pts
	else if(fg == 1)subtask2 :: main(); //64pts
	else subtask3 :: main();
	//-114514 pts
	return 0;
}
