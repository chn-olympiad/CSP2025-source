#include <bits/stdc++.h>
using namespace std;
int n,a[5010],ans;
bool vis[5010];
void check(){
	int sum = 0,cnt = 0,mx = 0;
	for (int i = 1;i <= n;i++){
		if (vis[i]){
			cnt++;
			sum += a[i];
			mx = max(mx,a[i]);
		}
	}
	if (cnt >= 3 && sum > mx * 2) ans++;
}
void dfs(int x){
	if (x == n + 1){
		check();
		return ;
	}
	vis[x] = true;
	dfs(x+1);
	vis[x] = false;
	dfs(x+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	dfs(1);
	cout << ans % 998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}