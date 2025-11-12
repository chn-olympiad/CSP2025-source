#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, num;
	short seat[111];
	cin >> n >> m;
	num = n * m;
	for (int i = 0; i < num; ++i)
		cin >> seat[i];
	int r = seat[0];
	sort(seat, seat + num);
	int rn = 1, rm = 1, i = 1;
	while (num--) {
		if (rm % 2 == 1)
			rn = i - (rm - 1) * n;
		else
			rn = rm * n - i + 1;
		if (seat[num] == r) {
			cout << rm << " " << rn;
			break;
		}
		++i;
		if (rn == n)
			rn = 1, ++rm;
	}
	return 0;
}
