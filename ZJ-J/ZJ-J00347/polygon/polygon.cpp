#include<bits/stdc++.h>
using namespace std;
#define LL long long
namespace Elysia{
	const LL mod = 998244353;
	const int N = 5005;
	LL cnt[N];
	int n;
	LL ans = 0;
	LL fast_power(LL x,int y){
		if(y == 0) return 1;
		if(y == 1) return x;
		LL re = fast_power(x,y/2);
		re *= re;
		re %= mod;
		if(y & 1) re *= x;
		return (re % mod);
	}
	LL a[N];
	void Solve(){
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		sort(a+1,a+1+n);
		LL ans = fast_power(2,n);
		cnt[0] = 1;
		ans = (ans - n - 1 + mod) % mod;
		for(int i=1;i<=n;i++){
			LL sum = 0;
			for(int j=1;j<=a[i];j++){
				sum += cnt[j];
				sum %= mod;
			}
			ans = (ans - sum + mod) % mod;
			for(int j=5000-a[i];j>=0;j--){
				cnt[j+a[i]] += cnt[j];
				cnt[j+a[i]] %= mod;
			}
		}
		cout << ans;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	Elysia::Solve();
	return 0;
}
// 9:40 Finished
//CSP-S RP++;