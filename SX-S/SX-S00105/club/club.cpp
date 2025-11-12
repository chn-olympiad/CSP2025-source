#include <bits/stdc++.h>
using namespace std;

struct xx_l {
	int a, b, c;
} xiaolian[100010];

int n = 0, t = 0, ans = -1, wei[4] ;

void dfs(int k, int ta, int sum) { //k表示层数，也是人的标号,ta是每一位上可以有的最多人数,
	if (k > n) {
		ans = max(ans, sum);
		return;
	}
	for (int z = 1; z <= 3; z++) {
		if (wei[z] < ta) {
			if (z == 1) {
				sum += xiaolian[k].a;
			} else if (z == 2) {
				sum += xiaolian[k].b;
			} else {
				sum += xiaolian[k].c;
			}
			wei[z]++;
			//	cout << k << ' ' << wei[z] << ' ' << z << ' ' << sum << endl;
			dfs(k + 1, ta, sum);
			wei[z]--;
			if (z == 1) {
				sum -= xiaolian[k].a;
			} else if (z == 2) {
				sum -= xiaolian[k].b;
			} else {
				sum -= xiaolian[k].c;
			}

		}
	}
	return;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int xi_i = 0; xi_i < t; xi_i++) {
		cin >> n;
		for (int z = 1; z <= n; z++) {
			cin >> xiaolian[z].a >> xiaolian[z].b >> xiaolian[z].c;
		}
		//	cout << n / 2 << endl;
		dfs(1, n / 2, 0);
		cout << ans << endl;
		ans = -1;
	}
	return 0;
}\
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/