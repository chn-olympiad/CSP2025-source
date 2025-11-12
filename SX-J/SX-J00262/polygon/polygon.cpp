#include <bits/stdc++.h>
using namespace std;
int n;
int a[10005];
string zh[10005];
string h;

string dfs(int i, int j, int ans, int sum) {

	if (ans == sum * 2) {
		return h;
	}
	int flag = 0;
	for (int k = j; j <= n; k++) {
		if (a[k] == 0)
			flag = 1;
	}
	if (flag == 0)
		return h;
	a[j] = 1;
	ans += a[j];
	sum = max(a[j], sum);
	h += a[j];
	for (int k = j; k <= n; k++) {
		dfs(i, k, ans, sum);
	}
	a[j] -= 1;
	return h;
}

int main() {

	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int ans2 = 0;
	int flag1 = 1;
	cin >> n;
	if (n <= 3) {
		int ans = 0, mymax = 0;
		if (n = 3) {
			for (int i = 1; i <= n; i++) {
				cin >> a[i];
				ans += a[i];
				mymax = max(mymax, a[i]);
			}
			if (ans >= mymax * 2)
				cout << 1;
			else
				cout << 0;
			return 0;
		}
		cout << 0;
		return 0;
	} else {
		for (int i = 4; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int b = 0;
				string ans1 = dfs(i, j, 0, 0);
				for (int k = 0; k <= b; k++) {
					if (ans1 == zh[k])
						flag1 = 0;
				}
				if (flag1 != 0) {
					b++;
					zh[b] = ans1;
					ans2++;
				}
			}
		}
	}
	cout << ans2;
	return 0;

}
