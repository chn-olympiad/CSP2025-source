#include <bits/stdc++.h>
const int N = 1e5+10;
using namespace std;

int a[N][10];
int z[10];
int ans, sum;
int n;

void dfs(int tep) {


	if (tep > n) {
		sum = max(ans, sum);

		return ;
	}
	for (int i = 1; i <= 3; i++) {
		if (z[i] + 1 > n / 2)
			continue;
//		cout << a[tep][i] << "   ";
		z[i]++;
		ans += a[tep][i];
		dfs(tep + 1);
		ans -= a[tep][i];
		z[i]--;
	}

}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		memset(z, 0, sizeof(z));
		cin >> n;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
			}
		ans = 0;
		sum = 0;
		dfs(1);
		cout << sum << '\n';
	}
	return 0;
}

