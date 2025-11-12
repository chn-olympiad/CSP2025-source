#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.ans", "w", stdout);
	//定义变量
	int n, m, r;
	cin >> n >> m;
	int s_room[n * m];
	int b_room[n][m];
	//输入
	for (int i = 0; i < n * m; i++) {
		cin >> s_room[i];
	}
	r = s_room[0];
	//排序
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s_room[j] < s_room[j + 1]) {
				swap(s_room[j], s_room[j + 1]);
			}
		}
	}
	//排位
	int f = 1;
	int i1 = 0;
	int j1 = 0;
	int c0 = 0;
	while (f) {
		b_room[i1][j1] = s_room[c0];
		if (i1 + 1 % m == 0)
			i1++;
		else if (i1 % 2 == 1)
			j1++;
		else if (i1 % 2 == 0)
			j1--;
		c0++;
		if (c0 == n * m)
			f = 0;

	}
	//查找
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (b_room[i][j] == r) {
				cout << i + 1 << j + 1;
				return 0;
			}
		}
	}
	return 0;
}
