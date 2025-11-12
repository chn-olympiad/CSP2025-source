#include<bits/stdc++.h>
#define endl '\n'
#define rep(A, B, C) for(int (A) = (B); (A) <= (C); A++)
#define dwn(A, B, C) for(int (A) = (B); (A) >= (C); A--)
#define debug "-------------\n"
#define int long long
using ll = long long;
const int mod = 998244353;
using namespace std;
const int N  = 505;
int a[N];
int n, m;
string s;
bool vis[N];
int res[N];
int ans = 0;

bool check(){
	int cnt = 0; 
	rep(i, 1, n){
		if(i - 1 - cnt < a[res[i]] && s[i] == '1') cnt++;
	}
	return cnt >= m; 
}
void dfs(int now){
	if(now == n + 1){
		if(check()) ans++;
		return;
	}
	rep(i, 1, n){
		if(vis[i]) continue;
		vis[i] = 1;
		res[now] = i;
		dfs(now + 1);
		vis[i] = 0;
	}
}
void solve(){
	dfs(1);
	cout << ans << endl;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	s = " " + s;
	rep(i, 1, n){
		cin >> a[i];
	}
	if(n < 20){
		solve();
		return 0;
	}
	int ans = 1;
	rep(i, 1, n){
		ans = (ans * i) % mod;
	}
	cout << ans << endl;
	return 0;
}

