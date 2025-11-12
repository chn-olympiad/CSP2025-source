#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[110];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++) 
		cin >> a[i]; 
	int b = a[1], res;
	sort(a+1, a+n*m+1, cmp);
	for (int i = 1; i <= n*m; i++) {
		if (a[i] == b) {
			res = i;
			break;
		} 
	}
	if (res == 1) cout << 1 << ' ' << 1;
	int x = 1, y = 1;
	bool f = 1;
	for (int i = 2; i <= res; i++) {
		if (f) {
			if (y == n) {
				x++;
				f = 0;
			} else {
				y++;
			}
		} else {
			if (y == 1) {
				x++;
				f = 1;
			} else {
				y--;
			}
		}
	}
	cout << x << ' ' << y;
	return 0;
}
