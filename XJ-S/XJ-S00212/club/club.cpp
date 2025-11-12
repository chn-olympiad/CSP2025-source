#include<bits/stdc++.h>
using namespace std;

int n;
const int MAXN = 1e5 + 10;
int a[MAXN][5];
int ans = -1;

void input() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= 3; j++) {
			cin >> a[i][j];
		}
	}
}

bool pd(int lm, int t1, int t2, int t3, int i) {
	if((i == 1 && t1 + 1 > lm) || (i == 2 && t2 + 1 > lm) || (i == 3 && t3 + 1 > lm)) {
		return true;
	}
	return false;
}

void dfs(int m, int sum, int t1, int t2, int t3) {
	int lm = n / 2;

	for(int i = 1; i <= 3; ++i) {
		if((m <= n) && pd(lm, t1, t2, t3, i)) {
			continue;
		}
		
		if(m == n + 1) {
			if(sum >= ans) ans = sum;
			return ;
		}

		if(i == 1) 		dfs(m + 1, sum + a[m][i], t1 + 1, t2, t3);
		else if(i == 2) dfs(m + 1, sum + a[m][i], t1, t2 + 1, t3);
		else if(i == 3) dfs(m + 1, sum + a[m][i], t1, t2, t3 + 1);
	}
}

void solve() {
	ans = -1;
	dfs(1, 0, 0, 0, 0);
}

void output() {
	cout << ans << endl;
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	int T;
	cin >> T;

	for(int i = 1; i <= T; i++) {
		input();
		solve();
		output();
	}

	return 0;
}
