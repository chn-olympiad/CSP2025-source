#include <bits/stdc++.h>
using namespace std;
int cj[110];

int main() {

	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, bj;
	cin >> n >> m;
	int sum = n * m;
	cin >> cj[1];
	int r = cj[1];
	for (int i = 2; i <= sum; i++) {
		cin >> cj[i];
	}
	sort(cj + 1, cj + 1 + sum);
	for (int i = 1; i <= sum; i++) {

		//cout << cj[i] << "¡¡";
		if (cj[i] == r) {
			bj = i;
			break;
		}
	}
	bj = sum - bj + 1;
	cout << (bj - 1) / n  + 1 << " ";
	if (bj % (2 * n) <= n)
		cout << bj % (2 * n) ;
	else
		cout <<   bj % (2 * n) - n + 1;

//	cout << bj;
	return 0;
}/*
3 3
94 95 96 97 98 99 100 93 92
*/
