#include <bits/stdc++.h>
using namespace std;
struct info { int scr, r; };
bool cmp(info a, info b) { return a.scr > b.scr; }

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<info> a(n * m);
	cin >> a[0].scr; a[0].r = 1;
	for (int i = 1;i < n * m;i++) (cin >> a[i].scr, a[i].r = 0);
	sort(a.begin(), a.end(), cmp);
	int x = 0, y = 0, flag = 0, dir = 1;
	for (int i = 0;i < n * m;i++) {
		if (a[i].r) {
			cout << y + 1 << " " << x + 1;
			break; 
		}
		if ((y % 2 == 0 && x == n-1) || (y % 2 == 1 && x == 0)) y++;
		else if (y % 2 == 0) x++;
		else if (y % 2 == 1) x--;
	}
	return 0;
}
