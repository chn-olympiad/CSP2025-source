#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;
int a[6000];
int n , ans = 0;
bool b = 1;
void dfs(int step , int sum , int mx) {
	if(step == n + 1) {
		if(sum > 2 * mx)ans++;
		return;
	}
	dfs(step + 1 , sum , mx);
	dfs(step + 1 , sum + a[step] , max(mx , a[step]));
}
int main() {
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] != 1)b = 0;
	}
	if(b) {
		int ans = 1;
		while(n--) {
			ans *= 2;
			ans %= M;
		}
		ans -= 1;
		ans %= M;
		cout << ans;
		return 0;
	}
	dfs(1 , 0 , 0);
	cout << ans;
	return 0;
}
