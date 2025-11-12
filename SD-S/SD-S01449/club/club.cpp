#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn][4], n, t, ans = -1;
void dfs(int k, int c1, int c2, int c3, int sum){
	if (k == n){
		ans = max(sum, ans);
		return ;
	}
	if (c1 + 1 <= n / 2){
		dfs(k + 1, c1 + 1, c2, c3, sum + a[k + 1][1]);
	}
	if (c2 + 1 <= n / 2){
		dfs(k + 1, c1, c2 + 1, c3, sum + a[k + 1][2]);
	}
	if (c3 + 1 <= n / 2){
		dfs(k + 1, c1, c2, c3 + 1, sum + a[k + 1][3]);
	}
	return ;
}
void init(){
	for (int i = 1;i <= n;i ++){
		a[i][1] = a[i][2] = a[i][3] = 0;
	}
	ans = -1;
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t --){
		init();
		cin >> n;
		for (int i = 1;i <= n;i ++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		dfs(0,0,0,0,0);
		cout << ans << '\n';
	}
	return 0;
}
