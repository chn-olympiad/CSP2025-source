#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n,a[5005],xz[25],ans,g;
void dfs(int s){
	if(s == n+1){
		int maxn = -0x3f3f3f3f,cnt = 0,sum = 0;
		for(int i = 1;i <= n;i++)
			if(xz[i]){
				sum++;
				maxn = max(maxn,a[i]);
				cnt += a[i];
			}
		if(cnt > maxn*2 && sum >= 3){
			ans++;
		}
		return;
	}
	dfs(s+1);
	xz[s] = 1;
	dfs(s+1);
	xz[s] = 0;
	return;
}
int C(int x,int y){
	__int128 f = 1;
	for(int i = x;i >= x-y+1;i--)
		f *= i;
	for(int j = 1;j <= y;j++)
		f /= j;
	return (int)f;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n;
	int maxn1 = -0x3f3f3f3f;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		maxn1 = max(maxn1,a[i]);
	}
	if(n <= 20){
		dfs(1);
		cout << ans%mod << '\n';
	}
	else if(maxn1 == 1){
		for(int i = 3;i <= n;i++)
			ans = (ans+C(n,i))%mod;
		cout << ans << '\n';
	}
	else
		cout << "CCF你的数据过于强大，长大以后我才能跑你这个数据呦~" << '\n';
	return 0;
}
/* 
	               ◢◤
	           ◢▆◤
	   ◢   ◢▇◤
	 ◢▇▆▇◤
	 ◥▇▇◤
     Just Do It
   尽管我无法证明他的对错，
   	   但我坚信他是对的
*/
