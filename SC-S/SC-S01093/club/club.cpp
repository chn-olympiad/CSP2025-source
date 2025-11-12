#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int T, n;
int a[N][4];
int ans;
void dfs(int x, int s, int num[4]) {
	if (x == n + 1) {
		ans = max(ans, s);
		return;
	}
	for (int i = 1; i <= 3; i++) {
		if (num[i] < n / 2) {
			num[i]++;
//			cout<<x<<" "<<i<<'\n';
			dfs(x + 1, s + a[x][i], num);
			num[i]--;
		}
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		int num[4] = {0};
		ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
			}
		}
		dfs(1, 0, num);
		cout << ans << '\n';
	}
	return 0;
}