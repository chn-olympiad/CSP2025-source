#include <bits/stdc++.h>
#define pii pair<int,int>
#define fir first
#define sec second
#define IO ios::sync_with_stdio(0);cin.tie(0);
//#define int long long
#define clr(x) memset(x,0,sizeof(x))
#define cmax(x) memset(x,0x3f,sizeof(x))
#define inf 0x3f3f3f3f3f3f3f3fll
#define INF 0x3f3f3f3f
#define finf -0x3f3f3f3f
#define ls (x << 1)
#define rs ((x << 1) | 1)
#define mid ((l + r) >> 1)
#define maxn 500010
#define maxm 1100000
#define lowbit(x) (x & (-x))
//#define mod 998244353
#define ll long long
#define endl '\n'
using namespace std;
ll n,m;
ll a[maxn];
ll t[maxm];
ll s[maxn];
ll mx[maxn];
ll dp[maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		s[i] = a[i] ^ s[i - 1];
	}
	memset(t,-1,sizeof(t));
	t[0] = 0;
	for(ll i = 1;i <= n;i++){
		dp[i] = dp[i - 1];
//		cout << (s[i] ^ m) << " " << s[i] << " " << t[s[i] ^ m] << " ";
		if(t[s[i] ^ m] != -1){
			dp[i] = max(dp[i],mx[t[s[i] ^ m]] + 1);
		}
		t[s[i]] = max(t[s[i]],i);
		mx[i] = max(mx[i - 1],dp[i]);
//		cout << t[s[i]] << " " << mx[i] << " " << dp[i] << endl;
	}
	cout << dp[n] << endl;
	return 0;
}
