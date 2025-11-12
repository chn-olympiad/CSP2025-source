#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int N = 5100;
int n,a[N],mxx;
ll ans;
void dfs(int p,int sum,int mx,int cnt){
	if(p == n + 1){
		if(sum > mx * 2 && cnt > 2){
			ans++;
		}
		return ;
	}
	dfs(p + 1,sum + a[p],max(mx,a[p]),cnt + 1);
	dfs(p + 1,sum,mx,cnt);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;++i){
		cin >> a[i];
		mxx = max(mxx,a[i]);
	}
	if(mxx == 1){
		ans = 1;
		for(int i = 1;i <= n;++i){
			ans *= 2;
			ans %= mod;
		}
		ans--;
		ans -= n;
		for(int i = 1;i <= n;++i){
			ans -= (n - i);
		}
		ans %= mod;
		for(int i = 1;i <= n - 2;++i){
			for(int j = i + 1;j < n;++j){
				ans -= n - j;
			}
			ans %= mod;
		}
		cout << (ans + mod) % mod;
		return 0;
	}
	dfs(1,0,0,0);
	cout << ans;
	return 0;
}
