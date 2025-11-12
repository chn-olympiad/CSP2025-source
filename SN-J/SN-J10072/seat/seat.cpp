#include <bits/stdc++.h>
using namespace std;
const int XN=1e3+10;
int n, m, a[XN], pos=1;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++) {
		cin >> a[i];
		if (a[i] > a[1])
			pos++;
	}
	int x=(pos-1)/n+1, y=(pos-1)%n+1;
//	cout << pos << "\n";
	if (x%2) cout << x << ' ' << y;
	else cout << x << ' ' << n-y+1; 
	return 0;
}
