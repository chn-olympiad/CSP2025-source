#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+10;
int ans[N][N];
struct Node {
	int x, Id;
}a[N];
bool cmp(Node x, Node y) {
	return x.x > y.x;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++) {
		cin >> a[i].x;
		a[i].Id = i;
	}
	sort(a+1,a+n*m+1,cmp);
	int x = 1, y = 1, f = 1;
	for (int i = 1; i <= n*m; i++) {
		if (a[i].Id == 1) {
			cout << x << ' ' << y << "\n";
			return 0;
		}
		if (f) {
			if (y == n) x++, f=0;
			else y++;
		} else {
			if (y == 1) x++, f=1;
			else y--;
		}
	}
	return 0;
}
