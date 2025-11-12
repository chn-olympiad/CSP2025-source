#include <bits/stdc++.h>
using namespace std;
int n, m, sum, st, dir;//chengji weizhi
int h, w;//lie hang
int a[107];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	sum = n * m;
	for (int i = 1; i <= sum; ++i) {
		cin >> a[i];
	}
	st = a[1];
	sort(a + 1, a + sum + 1);
	reverse(a + 1, a + sum + 1);
	for (int i = 1; i <= sum; ++i) {
		if (a[i] == st) {
			dir = i;
			break;
		}
	}
	h = ceil((double)dir / n);
	if (h % 2 == 1) {
		w = (dir - 1) % n + 1;
	}
	else {
		w = n + 1 - ((dir - 1) % n + 1);
	}
	cout << h << " " << w;
} 

