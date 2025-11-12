#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

int T, n;
int a[maxn][5];

bool flag = false; 

int ans = 0;
int vis[5];
void dfs (int step, int sum) {
	if (step > n) {
		ans = max(ans, sum);
		return;
	}
	for (int i = 1; i <= 3; i++) {
		if (vis[i] < n/2) {
			vis[i]++;
			dfs(step + 1, sum + a[step][i]);
			vis[i]--;
		}
	}
}

bool cmp (int a, int b) {
	return a > b; 
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
			if (a[i][2] != 0 || a[i][3] != 0) flag = true;
		}
		
		if (flag == false) {
			int b[maxn];
			for (int i = 1; i <= n; i++) {
				b[i] = a[i][1];
			}
			int ans = 0;
			sort(b + 1, b + 1 + n, cmp);
			for (int i = 1; i <= n/2; i++) {
				ans += b[i];
			}
			printf("%d\n", ans);
			return 0;
		}
		
		dfs(1, 0);
		printf("%d\n", ans);
		memset(vis, 0, sizeof vis);
		ans = 0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
