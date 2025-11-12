#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[105], s;

bool cmp(int n1, int n2) {
	return  n1 > n2;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m; //先行后列
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if (i == 1)
			s = a[i];
	}
	sort(a + 1, a + 1 + n *m, cmp);
	int x = 1, y = 1; //先列后行
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == s) {
			cout << x << ' ' << y;
			return 0;
		}
		if (x % 2 == 1) {
			y++;
			if (y == n + 1)
				y = n, x++;
		} else {
			y--;
			if (y == 0)
				y = 1, x++;
		}
	}
	return 0;
	//来吧跟我一起
	//我们在大坝最中央
	//来跟老祖一起
	//堆高高草莓塔
	//（嘿！！！）
	//天天爱打洲洲
	//卡个战备就出发
	//天天爱打洲洲
	//跟着老祖搓粑粑
	//天天爱打洲洲
	//跟着老祖飞溅粑——粑！
}