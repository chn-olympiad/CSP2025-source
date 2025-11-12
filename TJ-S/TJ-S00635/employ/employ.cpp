#include <iostream>
#include <cstdio>
using namespace std;
int n,m,b[501],vis[11],c[11];
char a[501];
const int mod = 998244353;
long long ans = 0,ans2 = 1;
void dfs(int dep){
	if (dep > n){
		int cnt = 0;
		for(int i = 1;i <= n;i++){
			if (cnt >= b[c[i]]) cnt++;
			else if (a[i] == '0') cnt++;
		}
		if (n-cnt >= m) ans++;
		return;
	}
	for (int i = 1;i <= n;i++){
		if (vis[i]) continue;
		vis[i] = 1;
		c[dep] = i;
		dfs(dep+1);
		vis[i] = 0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++) cin >> b[i];
	if (n <= 18){
		dfs(1);
		cout << ans;
	}
	else cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
