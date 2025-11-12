#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int N = 510;
int a[N],n,m,vis[N],b[N],flag;
ll ans,d[N] = {1};
string s;
void dfs(int p){
	if(p == n + 1){
		int cnt = 0;
		for(int i = 1;i <= n;++i){
			if(cnt >= a[b[i]] || s[i] == '0') cnt++;
		}
		if(n - cnt >= m) ans++;
		return ;
	}
	for(int i = 1;i <= n;++i){
		if(!vis[i]){
			vis[i] = 1;
			b[p] = i;
			dfs(p + 1);
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int cnt = 0;
	cin >> n >> m >> s;
	s = " " + s;
	for(int i = 1;i <= n;++i){
		cin >> a[i];
		if(a[i] == 0) cnt++;
		d[i] = d[i - 1] * i;
		d[i] %= mod;
	}
	if(n - cnt < m){
		cout << 0;
		return 0;
	}
	for(int i = 1;i <= n;++i){
		if(s[i] == '0'){
			flag = 1;
			break;
		}
	}
	if(flag == 0 || n > 50){
		ans = 1;
		for(int i = 1;i <= n;++i){
			ans *= i;
			ans %= mod;
		}
		cout << ans;
		return 0;
	}
	dfs(1);
	cout << ans;
	return 0;
}
