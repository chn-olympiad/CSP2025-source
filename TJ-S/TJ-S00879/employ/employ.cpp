#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,m,c[11],flag[11],a[11],ans;
string s;
void dfs(int x){
	if (x == n){
		int cnt = 0,cc = 0;
		for (int i = 1;i <= n;i++){
			if (s[i - 1] == '0'){
				cc++;
			}else{
				if (cc >= c[a[i]]){
					cc++;
				}else{
					cnt++;
				}
			}
		}
		if (cnt >= m){
			ans++;
			ans %= mod;
		}
		return ;
	}
	for (int i = 1;i <= n;i++){
		if (!flag[i]){
			a[x + 1] = i;
			flag[i] = true;
			dfs(x + 1);
			flag[i] = false;
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1;i <= n;i++){
		cin >> c[i];
	}
	dfs(0);
	cout << ans % mod;
	return 0;
}
