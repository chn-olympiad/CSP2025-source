#include<bits/stdc++.h>
#define N 5039
using namespace std;
const long long M = 998244353; 
bool vis[N];
long long a[N], ans, n, maxn, sum, num;
void dp (int stp) {
	if (stp == n + 1) {
		maxn = sum = 0;
		for (int i = 1; i <= n; i++) {
			if (vis[i] == 1) {
				maxn = max (maxn, a[i]);
				sum += a[i];
				vis[i] = '0';
				num++;
			}
		}
		if (num < 3) return ;
		if ((maxn * 2) < sum) {
			ans = ans % M + 1;
		}		
		return ;
	}
	dp (stp + 1);
	vis[stp] = 1;
	dp (stp + 1);
	vis[stp] = 0;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dp(1);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}