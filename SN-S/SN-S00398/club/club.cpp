#include <bits/stdc++.h>

using namespace std;

int n, t, a[205][5], ans;

void dfs(int l, int l1, int l2, int l3, int sum) {
	if(l > n) {
		ans = max(ans, sum);
		return ;
	}
	if(l1 < n/2) dfs(l+1, l1+1, l2, l3, sum+a[l][1]);
	if(l2 < n/2) dfs(l+1, l1, l2+1, l3, sum+a[l][2]);
	if(l3 < n/2) dfs(l+1, l1, l2, l3+1, sum+a[l][3]);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--) {
		cin >> n;
		ans = 0;
		for(int i = 1; i <= n; i++) cin >> a[i][1] >> a[i][2] >> a[i][3];
		dfs(1, 0, 0, 0, 0);
		cout << ans << "\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
