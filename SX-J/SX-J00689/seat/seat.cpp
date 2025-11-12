#include <bits/stdc++.h>
using namespace std;

int cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int ans;//小R
	int a[1001];//数组
	//cout << n << m;
	for (int i = 1; i <= n * m; i++) {
		//cout << "test" << endl;
		if (i == 1) {
			int x;
			cin >> x;
			a[i] = x;
			ans = x;
			continue;
		} else {
			int x;
			cin >> x;
			a[i] = x;
		}
	}//输入
	sort(a + 1, a + n *m + 1, cmp);
	int i = 1, j = 1;
	int k = 1; //第几个
	bool flag = true;
	while (true) {
		if (i <= n && flag == true) {
			if (a[k] == ans) {
				cout << j << " " << i << endl;
				return 0;
			}
			if (i == n) {
				j += 1;
				k++;
				flag = false;
			} else
				i++, k++;
		}
		if (j <= m && flag == false) {
			if (a[k] == ans) {
				cout << j << " " << i << endl;
				return 0;
			}
			if (i == 1) {
				j += 1;
				k++;
				flag = true;
			} else
				i--, k++;
		}
	}
	return 0;
}