//SN-J00369 张正轩 西安高新第一中学 
#include<bits/stdc++.h>
using namespace std;
struct node {
	int point;
	bool flag;
}a[105];
bool cmp(node a, node b) {
	return a.point > b.point;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout); 
	int n, m, x, y, s;
	cin >> n >> m;
	a[1].flag = 1;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i].point;
	}
	sort(a + 1, a + 1 + n * m, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i].flag == 1) {
			s = i;
			break;
		}
	}
	if (s % n != 0) {
		x = s / n + 1;
		if (x % 2 == 1) {
			y = s % n;
			cout << x << " " << y;
		}else {
			y = n - (s % n) + 1;
			cout << x << " " << y;
		}
	}else {
		x = s / n;
		if (x % 2 == 1) {
			cout << x << " " << n;
		}else {
			cout << x << " " << 1; 
		}
	}
	return 0;
}
