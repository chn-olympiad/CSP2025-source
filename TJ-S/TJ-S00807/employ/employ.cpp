#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 501,mod = 998244353;
int n,m,res = 0,a[N],c[N],pre[N],dp[1<<18|1][19];
bool st[N];
string s;
void dfs(const int &x){
	if(x == n+1){
		int now = 0;
		for(int i = 1;i<=n;++i){
			if(now>=c[a[i]]||s[i] == '0'){
				++now;
			}
		}
		if(n-now>=m){
			res = (res+1)%mod;
		}
		return;
	}
	for(int i = 1;i<=n;++i){
		if(!st[i]){
			a[x] = i;
			st[i] = true;
			dfs(x+1);
			st[i] = false;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	cin >> s;
	s = '#'+s;
	for(int i = 1;i<s.size();++i){
		pre[i] = pre[i-1]+(s[i] == '1');
	}
	for(int i = 1;i<=n;++i){
		cin >> c[i];
	}
	if(n<=10){
		dfs(1);
		cout << res;
	}else if(m == n){
		bool flag = true;
		for(int i = 1;i<=n;++i){
			if(s[i] == '0'||c[i] == 0){
				flag = false;
				break;
			}
		}
		if(!flag){
			cout << 0;
		}else{
			res = 1;
			for(int i = 2;i<=n;++i){
				res = res*i%mod;
			}
			cout << res;
		}
	}else if(n<=18){
		dp[0][0] = 1;
		for(int i = 1;i<(1<<n);++i){
			int cnt = 0;
			for(int j = 1;j<=n;++j){
				cnt+=(bool)(i&(1<<j-1));
			}
			for(int j = 1;j<=n;++j){
				if(i&(1<<j-1)){
					int num = (i^(1<<j-1));
					for(int k = 0;k<=cnt;++k){
						if(s[cnt] == '0'||c[j]<=cnt-k){
							dp[i][k] = (dp[i][k]+dp[num][k])%mod;
						}else{
							dp[i][k] = (dp[i][k]+dp[num][k-1])%mod;
						}
					}
				}
			}
		}
		int sum = 0;
		for(int i = m;i<=n;++i){
			sum = (sum+dp[(1<<n)-1][i]);
			cout << dp[(1<<n)-1][i] << " ";
		}
		cout << sum%mod;
	}
	return 0;
}
