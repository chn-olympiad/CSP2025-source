#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
const int mod = 998244353;
#define N 505
int n,m,ans;
string s;
int c[N];
bool vis[N];
int u[N];
void dfs(int i,int cnt){
	if(cnt >= m){
		ans += u[n - i + 1];
		return;
	}
	if(cnt + n - i + 1 < m)return;
	if(i == n + 1)return;
	for(int j = 1; j <= n; j++){
		if(!vis[j]){
			vis[j] = true;
			if(c[j] >= i){
				dfs(i + 1,cnt + 1);
			}else{
				dfs(i + 1,cnt);
			}
			vis[j] = false;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(vis,false,sizeof(vis));
	ans = 0;
	cin >> n >> m;
	cin >> s;
	s = " " + s;
	int cnt = 0;
	u[0] = 1;
	for(int i = 1; i <= n; i++){
		u[i] = 1ll * u[i - 1] * i % mod;
	}
	for(int i = 1; i <= n; i++){
		cin >> c[i];
		if(s[i] == '1')++cnt;
	}
	if(cnt < m){
		cout << 0 << endl;
	}else{
		ans = 0;
		dfs(1,0);
		cout << ans << endl;
	}
	return 0;
}

