#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N][3];
int tmp = 0;
int ans = 0;
int si[3];
int n;
int x;
void dfs() {
	if (x > n) {
		return ;
	}
	for (int i = 0; i <= 2; i++) {
		if (si[i] > 0) {
			si[i] -= 1;
			tmp += a[x][i];
			ans = max(tmp, ans);x++;
			dfs();
			x--;
			si[i]++;
			tmp -= a[x][i];
		}

	}


	return ;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		memset(a, 0, sizeof a);
		tmp = 0;
		ans = 0;


		cin >> n;
		int maxx = n / 2;
		for (int i = 0; i <= 2; i++)
			si[i] = maxx;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		}
	x=1;
		dfs();
		cout << ans << '\n';
	}


}