#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e2 + 5, mod = 998244353;
bool s[N];
int c[N], a[N], vis[N], ans, n, m;
void sol(int k){
	if(k == n + 1){
		int r = 0, t = 0;
		for(int i = 1;i <= n;i ++){
			if(!s[i])r ++;
			else if(r >= c[a[i]])r ++;
			else t ++;
		}
		if(t >= m)ans ++, ans %= mod;
		return;
	}
	for(int i = 1;i <= n;i ++){
		if(vis[i])continue;
		vis[i] = 1;
		a[k] = i;
		sol(k + 1);
		vis[i] = 0;
	}
	return;
}
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	string str;cin >> str;
	bool f1 = 1;
	int uuu = 0;
	for(int i = 1;i <= n;i ++){
		s[i] = str[i - 1] - '0';
		uuu += s[i];
		f1 &= s[i];
		cin >> c[i];
	}
	if(uuu < m){
		cout << 0 << '\n';
		return 0;
	}
	sol(1);
	cout << ans << '\n';
	if(f1){
		int sum = 0;
		for(int i = 1;i <= n;i ++)sum += (c[i] != 0);
		if(sum >= m){
			int ans = 1;
			for(int i = 1;i <= n;i ++)ans *= i, ans %= mod;
			cout << ans << '\n';
		}
		else {
			cout << 0 << '\n';return 0;
		}
	}
	return 0;
}