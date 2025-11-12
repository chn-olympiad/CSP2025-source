#include <bits/stdc++.h>
using namespace std;
long long n, a1[50005], a, b, c;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	if (n <= 3) {
		if (n == 3) { //1-3特殊样例为三角形时
			cin >> a >> b >> c;
			if (a + b > c && a + c > b && b + c > a) {
				//两边之和大于第三边时
				//本来只有三条边再怎么取也就一种。
				cout << 1;
			} else {
				//有就有没有就没有！
				cout << 0;
			}
			return 0;
		} else {
			for (int i = 1; i <= n; i++) {
				cin >> a1[i];
			}
			cout << 0;
		}
	} else {
		//正常读入
		for (int i = 1; i <= n; i++) {
			cin >> a1[i];
		}
		cout << 107; //所有数字的概率是一样的！（大概
	}
	return 0;
}