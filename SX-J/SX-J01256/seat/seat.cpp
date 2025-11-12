#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, t, cj, wz, ansx, ansy;
priority_queue<int> que;

int main() {

	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;//小 R 所在的考场座位的行数n与列数m
	for (int i = 1; i <= n * m; i++) {
		cin >> t;
		if (i == 1) {
			cj = t; //小R的成绩
		}
		que.push(t);//大根堆，由大到小排序
	}
	while (!que.empty()) {
		cnt++;//名次++
		if (que.top() == cj) {
			wz = cnt;//找到了，wz定义名次
		}
		que.pop();
	}
	if (wz / n != 0) {// 不是 特例1：在第一列
		if ( wz % n == 0 ) { //特例2：在偶数列顶部或奇数列底部
			if (wz / n % 2 == 0) { //偶数列顶部
				ansx = wz / n, ansy = 1;
			} else { //奇数列底部
				ansx = wz / n, ansy = n;
			}
		} else { //非特例
			if (wz / n % 2 == 0) { //奇数列
				ansx = wz / n + 1, ansy = wz % n;
			} else { //偶数列
				ansx = wz / n + 1, ansy = n - wz % n + 1;
			}
		}
	} else { // 是 特例1：在第一列
		ansx = 1, ansy = wz;
	}
	cout << ansx << " " << ansy;


	return 0;
}
