#include <bits/stdc++.h>
using namespace std;

short t, z[3] = {0, 0, 0};
bool i10 = 0, i20 = 0, 130 = 0

                             long long ans = 0, sum = 0;
int  n = 0, h = 0, a[100005][3];

//AFO
//rp++;
//和溢位!!!

void dfs(int k) {
	if (k == n) {
		ans = max(ans, sum);
		return;
	}
	for (short i = 0; i < 3; i++) {
		if (z[i] == h) {
			continue;
		}
		sum += a[k][i];
		z[i]++;
		dfs(k + 1);
		sum -= a[k][i];
		z[i]--;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		ans = 0, sum = 0, n = 0, h = 0, z[0] = 0, z[1] = 0, z[2] = 0;
		cin >> n;
		h = n / 2;
		for (int i = 0; i < n; i++) {
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			if (a[i][0]) {
				i10 = 1;
			}
			if (a[i][1]) {
				i20 = 1;
			}
			if (a[i][2]) {
				i30 = 1;
			}
		}
		if ((!a[i][0] && !a[i][1]) || (!a[i][2] && !a[i][1]) || (!a[i][0] && !a[i][2])) {
			for (int i = 0; i < n; i++) {
				ans += a[i][0] + a[i][1] + a[i][2];
				cout << ans << "\n";
				return 0;
			}
		}
		//cout << "和溢位!!!";
		dfs(0);
		cout << ans << "\n";
	}
	flose(stdin);
	fclose(stdout);
	return 0;
}