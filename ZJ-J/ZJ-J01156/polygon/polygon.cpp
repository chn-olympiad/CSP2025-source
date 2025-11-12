#include<bits/stdc++.h>
using namespace std;
int n, a[5001], ans, all;
const int Mod = 998244353;
void dfs(int x, int ma, int tot, int sum){
	if(x == n + 1) {
		if(tot > ma * 2 and sum >= 3)  {
			ans++;
			ans %= Mod;
		}
		return ;
	}
	dfs(x + 1, ma, tot, sum);
	dfs(x + 1, a[x], tot + a[x], sum + 1);
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		all += a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = n;i >= 1;i--) {
		if(a[i] >= all * 2) {
			n--;
			all -= a[i];
		} else break;
	}
	dfs(1, 0, 0, 0); 
	cout << ans % Mod;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
