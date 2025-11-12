#include <bits/stdc++.h>
#define lid (id << 1)
#define rid (id << 1 | 1)
#define int long long
using namespace std;
const int N = 500005;
int n,k,a[N],dp[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	for(int i = 1;i <= n;i++){
		int u = 0;
		for(int j = i;j >= 1;j--){
			if(dp[i-1] - dp[j-1] > 1)
				break;
			u ^= a[j];
			dp[i] = max(dp[i],dp[j-1]+(int)(u == k));
		}
	}
	cout << dp[n] << '\n';
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
