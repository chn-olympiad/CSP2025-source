#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n,a[5005],vis[5005],num,k,ans = 0,p;
void dfs(int m){
	cout << ans << endl;
	if(num > k) {
		ans = (ans + 1) % mod;return ;
	}
	if(m >= p) return ;
	for(int i = 1;i <= n;i ++){
		if(i == p) break;
		if(!vis[i]){
			num += a[i];
			vis[i] = 1;
			dfs(m + 1);
			vis[i] = 0;
			num -= a[i];
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	if(n == 3){
		if(a[1] + a[2] > 2 * a[3]) cout << 1 ;
		else cout << 0;
		return 0;
	}
	for(int i = n;i >= 1;i --){
		k = 2 * a[i];p = i;
		num = 0;
		memset(vis,0,sizeof vis);vis[p] = 1;num += a[i];
		dfs(1);
	}
	cout << ans % mod;
	return 0;
}
