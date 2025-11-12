#include<bits/stdc++.h>
#define N 20
#define fo(a, b, c) for(int b = a; b <= c; b++)
#define _fo(a, b, c) for(int b = a; b >= c; b--)
#define Fo(a, b) for(auto a : b)
#define pb push_back
#define lb lower_bound
using namespace std;
#define int long long
int n, m, a[N], ans, vis[N], c[N];
string s;
void dfs(int x, int pre){
	if(x == n + 1){
		if(n - pre >= m) ans++;
		return;
	}
	fo(1, i, n){
		if(!vis[i]){
			vis[i] = 1;
			if(pre >= c[i] || a[x] == 0) dfs(x + 1, pre + 1);
			else dfs(x + 1, pre);
			vis[i] = 0; 
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> s, s = " "  + s;
	fo(1, i, n) a[i] = s[i] - '0';
	fo(1, i, n) cin >> c[i]; 
	dfs(1, 0);
	cout << ans;
	return 0;
}

