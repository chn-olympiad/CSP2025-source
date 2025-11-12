#include <bits/stdc++.h>

using namespace std;

int n, a[100005], ans = 0;

void dfs(int sum, int big, int l, int net) {
	if(l >= 3) {
		if(sum > 2 * big) {
			int k = lower_bound(a+1, a+n+1, big) - a;
			cout << l << ' ' << sum << ' ' << big << ' ' << a[k] << "\n";
			ans += n - k + 1;
		}
		return ;
	}
	for(int i = net; i <= n; i++) {
		dfs(sum + a[i], max(big, a[i]), l+1, i+1);
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	dfs(0, 0, 0, 1);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

