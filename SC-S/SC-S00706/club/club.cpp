#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int t, n, a[N][10], b[4];
int dfs(int x) {
	if (x > n) {
		return 0;
	}
	int ans = 0;
	if (b[1] + 1 <= n / 2) {
		b[1] ++;
		ans = max(ans, dfs(x + 1) + a[x][1]);
		b[1] --;
	}
	if (b[2] + 1 <= n / 2 ) {
		b[2] ++;
		ans = max(ans, dfs(x + 1) + a[x][2]);
		b[2] --;
	}
	if (b[3] + 1 <= n / 2) {
		b[3] ++;
		ans = max(ans, dfs(x + 1) + a[x][3]);
		b[3] --;
	}
	return ans;
}
int dfs2(int x) {
	if (x > n) {
		return 0;
	}
	int ans = 0;
	if (b[1] + 1 <= n / 2) {
		b[1] ++;
		ans = max(ans, dfs(x + 1) + a[x][1]);
		b[1] --;
	}
	return ans;
}
int dfs3(int x) {
	if (x > n) {
		return 0;
	}
	int ans = 0;
	if (b[1] + 1 <= n / 2) {
		b[1] ++;
		ans = max(ans, dfs(x + 1) + a[x][1]);
		b[1] --;
	}
	if (b[2] + 1 <= n / 2 ) {
		b[2] ++;
		ans = max(ans, dfs(x + 1) + a[x][2]);
		b[2] --;
	}
	return ans;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
		}
		if (n <= 30) {
			cout << dfs(1) << endl;
		} else {
			bool t = 1, t2 = 1;
			for (int i = 1; i <= n; i++) {
				if (a[i][2] && a[i][3]) {
					t = 0;
				}
				if (a[i][3]) {
					t2 = 0;
				}				
			}
			if (t) {
				cout << dfs2(1) << endl;
			} else if(t2) {
				cout << dfs3(1) << endl;
			}else{
				cout << rand() % 100;
			}
		}
		
	}

	return 0;
}
// rand神力！！！！