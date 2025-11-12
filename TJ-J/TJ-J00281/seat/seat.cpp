#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	int a[102], dp[102][102];
	cin >> m >> n;
	for (int i = 1;i <= m*n;i++) {
		cin >> a[i];
	}
	int b = a[1], index;
	sort (a+1, a+n*m, greater<int>());
	for (int i = 1;i <= m*n;i++) {
		//cout << a[i] << ' ' << i << endl;
		if (a[i] == b) {
			index = i;
			break;
		}
	}
	if ((index % m) == 0) {
		//cout << '1' << ' ' << index << endl;
		cout << index / m << ' ' << m;
		return 0;
	}
	if ((index / m) % 2 != 0){
		//cout << '2' << ' ' << index << endl;
		cout << index / m + 1 << ' ' << m - index % m + 1;
		return 0;
	}
	else {
		cout << index / m + 1 << ' ' << index % m;
		return 0;
	}
}
