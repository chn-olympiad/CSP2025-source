#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
long long a[N][5], b[N], ans, n, m, c[N];
void dfs(long long num, long long sum) {
	if(num > n) {
		ans = max(ans, sum);
		return ;
	}
	for (int i=1; i<=3; i++) {
		if(b[i] < m) {
			b[i]++;
			dfs(num+1, sum+a[num][i]);
			b[i]--;
		}
	}
}
int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	long long t;
	cin >> t;
	while(t--) {
		memset(b, 0, sizeof(b));
		ans = 0;
		cin >> n;
		m = n/2;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=3; j++) cin >> a[i][j];
		}
		if (n <= 30) dfs(1, 0);
		else {
			for(int i=1; i<=n; i++) c[i] = a[i][1];
			sort(c+1, c+1+n);
			for(int i=0; i<m; i++) ans += c[n-i];
		}
		cout << ans << endl;
	}
	return 0;
}
