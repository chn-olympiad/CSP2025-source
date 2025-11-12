#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

int read(){ int x = 0, f = 1; char ch = getchar(); while(!isdigit(ch)){ if(ch == '-') f = -1; ch = getchar(); } while(isdigit(ch)){ x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar(); } return x * f; }

const int M = 998244353;
const int N = 1e6 + 10;
int n, m, ans, v[N], c[N], d[N], a[N];
string s;

void dfs(int u, int k, int res){
	if(u == n + 1){
		if(res >= m) ++ ans;
		if(ans >= M) ans -= M;
		return;
	}
	for(int i = 1; i <= n; ++ i){
		if(!v[i]){
			v[i] = 1; a[u] = i;
			int x = 0; if(k >= c[i] || !d[u]) x = 1;
			dfs(u + 1, k + x, res + (x == 0));
			v[i] = 0;
		}
	}
}

signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m >> s;
	for(int i = 1; i <= n; ++ i){
		cin >> c[i]; d[i] = (s[i - 1] - '0'); 
	} dfs(1, 0, 0); cout << ans << "\n";
	
	return 0;
}
/*

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/

