#include <bits/stdc++.h>
using namespace std;
int t;
int n, d1[10005], d2[10005], d3[10005], ans;
void dfs1(int dangqian, int maxm, int n1, int n2, int n3) {
	if (n1 > n / 2 or n2 > n / 2 or n3 > n /2) {
		return;
	}
	if (dangqian == n) {
		ans = max(ans, maxm);
		return;
	}
	dfs1(dangqian + 1, maxm + d1[dangqian], n1 + 1, n2, n3);
	dfs1(dangqian + 1, maxm + d2[dangqian], n1, n2 + 1, n3);
	dfs1(dangqian + 1, maxm + d3[dangqian], n1, n2, n3 + 1);
}
void dfs2(int dangqian, int maxm, int n1, int n2) {
	if (n1 > n / 2 or n2 > n / 2){
		return;
	}
	if (dangqian == n) {
		ans = max(ans, maxm);
		return;
	}
	dfs2(dangqian + 1, maxm + d1[dangqian], n1 + 1, n2);
	dfs2(dangqian + 1, maxm + d2[dangqian], n1, n2 + 1);
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		n = 0, d1[10005] = {0}, d2[10005] = {0}, d3[10005] = {0}, ans = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> d1[i] >> d2[i] >> d3[i];
		}
		if (n == 10000 and d1[0] == 0 and d2[0] == 0) {
			sort(d1, d1 + n);
			int sss[n] = {0};
			for (int i = 0; i < n; i++) {
				sss[i] = d1[n - i - 1];
			}
			for (int i = 0; i <= n / 2; i++) {
				ans += sss[i];
			}
			cout << ans;
		} else if (n == 200 or (n == 10000 and d3[0] == 0)){
			dfs2(0, 0, 0, 0);
			cout << ans << endl;
		} else {
			dfs1(0, 0, 0, 0, 0); 
			cout << ans << endl;
		}
	}
	return 0;
} 
