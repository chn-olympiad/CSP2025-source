#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,a[N],dp[N],k,mx,p[N],cnt1,x[1010][1010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;++i){
		cin >> a[i];
		if(a[i] == 1) cnt1++;
		mx = max(mx,a[i]);
	}
	if(mx <= 1){
		if(k == 1) cout << cnt1;
		else if(k == 0){
			int ans = n - cnt1;
			for(int i = 2;i <= n;++i){
				if(a[i] == 1 && a[i - 1] == 1){
					a[i] = 0;
					ans++;
				}
			}
			cout << ans;
		}
		else cout << 0;
		return 0;
	}
	for(int i = 1;i <= n;++i){
		for(int j = i;j <= n;++j){
			x[i][j] = x[i][j - 1] ^ a[j];
		}
	}
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= i;++j){
			dp[i] = max(dp[i],dp[j - 1] + (x[j][i] == k ? 1 : 0));
		}
	}
	cout << dp[n];
	return 0;
}
