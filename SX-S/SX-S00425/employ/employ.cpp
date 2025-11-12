#include <bits/stdc++.h>
using namespace std;
int n, a[105], p[105], k, cnt, sum;
bool flag[105];
char op[105];

void dfs(int x, int num, int wo) {
	if (x == n + 1 && num >= k) {

		cnt++;
		//cnt %= 998244353;
		return ;
	}
	//cout << "x:" << x << "\nnum:" << num << "\n\n";
	for (int i = 1; i <= n; i++) {
		if (!flag[i]) {
			flag[i] = 1;
			if (op[x] == '1' && wo <= a[i] )
				dfs(x + 1, num + 1, wo);
			else
				dfs(x + 1, num, wo + 1);
			flag[i] = 0;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
//	cin >> n >> k;
//	for (int i = 1; i <= n; i++) {
//		cin >> op[i];
//		sum += ((op[i] == '1') ? 1 : 0);
//	}
//	if (sum < k) {
	cout << 0;
//		return 0;
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	dfs(1, 0, 0);
//	cout << cnt;
	return 0;
}
/*/

10 5
1111111111
6 0 4 2 1 2 5 4 3 3


*/