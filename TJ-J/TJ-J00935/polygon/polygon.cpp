#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
#define O(i,l,r) for (int i = l;i <= r;++i)
#define U(i,r,l) for (int i = r;i >= l;--i)
namespace wjx{
void FRE(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
}
void IOS(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int T_T = 1;
int n;
ll a[5005],sum[5005];
ll f[5005][5005];//f[i][j] biao shi qian i ge xiao mu gun zhong xuan di i ge xiao mu gun qie he >= j ke yi zu cheng de duo bian xing ge shu
ll g[5005];//g[i] biao shi qian i ge xiao mu gun zhong xuan di i ge xiao mu gun bing qie he >= 5000
//f[i][j] biao shi qian i ge xiao mu gun zhong xuan di i ge xiao mu gun qie he wei j ke yi zu cheng de duo bian xing ge shu
void get(){
	cin >> n;
	O(i,1,n) cin >> a[i];
	O(i,1,n) sum[i] = sum[i - 1] + a[i];
}

void solve(){
	sort(a + 1,a + n + 1);
	f[1][a[1]] = 1;
	ll ans = 0;
	O(i,2,n){
		f[i][a[i]] = 1;
		O(j,1,i - 1){
			O(k,1,min(sum[j],5000ll)){
				if (k + a[i] > 5000) g[i] = (g[i] + f[j][k]) % mod;
				else f[i][k + a[i]] = (f[i][k + a[i]] + f[j][k]) % mod;
			} //f[i][j] = sigma j = 1,i - 1
			g[i] = (g[i] + g[j]) % mod;
		}
	}
//	for (int i = 1;i <= n;++i){
//		for (int j = 1;j <= sum[i];++j) cout << i << ' ' << j << ' ' << f[i][j] << "\n";
//	}
	O(i,1,n){
		O(j,a[i] * 2 + 1,5000) ans = (ans + f[i][j]) % mod;
		ans = (ans + g[i]) % mod;
	}
	cout << ans << "\n";
}
//O(n * max(a_i))
/*
5
1 2 3 4 5

*/
signed main(){
//	cin >> T_T;
	while (T_T--){
		wjx::get();
		wjx::solve();
	}
	return 0;
}

}

signed main(){
//	wjx::IOS();
	wjx::FRE();
	return wjx::main();
}
/*
rp++
*/

