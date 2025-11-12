#include <bits/stdc++.h>
#define pii pair<int,int>
#define fir first
#define sec second
#define IO ios::sync_with_stdio(0);cin.tie(0);
#define clr(x) memset(x,0,sizeof(x))
#define cmax(x) memset(x,0x3f,sizeof(x))
#define inf 0x3f3f3f3f3f3f3f3fll
#define INF 0x3f3f3f3f
#define finf -0x3f3f3f3f
#define ls (x << 1)
#define rs ((x << 1) | 1)
#define mid ((l + r) >> 1)
#define maxn 5010
#define maxm 1100000
#define lowbit(x) (x & (-x))
#define mod 998244353
#define ll long long
#define endl '\n'
using namespace std;
ll n,m;
ll a[maxn];
ll dp[maxn][maxn];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
    	cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	dp[0][0] = 1;
	ll ans = 0;
	for(ll i = 1;i <= n;i++){
		if(i >= 3){
		    for(ll j = a[i] + 1;j <= 5001;j++){
				ans += dp[i - 1][j];
				ans %= mod; 
			}	
//			cout << ans << endl;
		}
		for(ll j = 0;j <= 5001;j++){
			dp[i][min(j + a[i],5001ll)] += dp[i - 1][j];
			dp[i][min(j + a[i],5001ll)] %= mod;
			dp[i][j] += dp[i - 1][j];
			dp[i][j] %= mod;
		}
	}
//	for(int i = 0;i <= n;i++){
//	    for(int j = 0;j <= 15;j++){
//	    	cout << dp[i][j] << " "; 
//		}
//		cout << endl;
//	}
	cout << ans << endl;
	return 0;
}
