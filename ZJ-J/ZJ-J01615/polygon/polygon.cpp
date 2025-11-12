#include<bits/stdc++.h>
using namespace std;
const int maxn = 998244353;
int n, a[10005], ans, k[10005], vis[10005];
void dfs(int sum, int level, int s) {
	if(level > sum) {
		int m = 0, num = 0;
		for(int i = 1;i <= sum;i++) {
			m = max(m, k[i]);
			num += k[i];
		}
		if(num > m * 2) ans++;
		return ;
	}
	for(int i = s;i <= n;i++) {
		if(vis[i]) continue;
		vis[i] = 1;
		k[level] = a[i];
		dfs(sum, level + 1, i + 1);
		vis[i] = 0;
	}
	return ;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for(int i = 1;i <= n;i++) 
		cin >> a[i];
	for(int i = 3;i <= n;i++) {
		for(int j = 1;j <= n;j++) k[j] = 0;
		dfs(i, 1, 1);
	}
	cout << ans << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}