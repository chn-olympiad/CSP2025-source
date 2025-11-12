#include<bits/stdc++.h>
using namespace std;
int f[100005][3];
int sum[4];
int n;
int bfs(int i, int a, int b, int c) {
	if (i == n + 1) {
		return 0;
	}
	int ans = 0;
	if (a < n / 2) {
		ans = max(ans, f[i][0] + bfs(i + 1, a + 1, b, c));
	}
	if (b < n / 2) {
		ans = max(ans, f[i][1] + bfs(i + 1, a, b + 1, c));
	}
	if (c < n / 2) {
		ans = max(ans, f[i][2] + bfs(i + 1, a, b, c + 1));
	}
	return ans;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> f[i][0] >> f[i][1] >> f[i][2];
		}
		cout << bfs(1, 0, 0, 0) << endl;
		for (int i = 1; i <= n; i++) {
			f[i][0] = 0;
			f[i][1] = 0;
			f[i][2] = 0;
		}
	}
	return 0;
}//AFO???
//i dont want
//i can't ak it
//i will do i think