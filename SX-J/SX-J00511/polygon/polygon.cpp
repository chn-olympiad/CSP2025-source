#include <bits/stdc++.h>
using namespace std;
int a[5010];//输入数组
int c[5010];//前缀和数组

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	int n;
	cin >> n;
	if (n == 3) { //骗分
		int num = 0;
		int maxn = -1;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			num += a[i];
			maxn = max(a[i], maxn);
		}
		if (num > maxn * 2)
			cout << 1;
		else
			cout << 0;
		return 0;
	}

	else { //正常代码
		int num = 0;
		c[0] = 0;
		c[1] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		sort(a + 1, a + n + 1);
		int maxn = -1;
		for (int j = 1; j <= n; j++) {
			c[j] = c[j - 1] + a[j];
			maxn = max(maxn, a[j]);
			if (maxn * 2 < c[j]) {
				num++;
				cout << maxn << " ";
			}
		}
		cout << num;
	}
	return 0;
}