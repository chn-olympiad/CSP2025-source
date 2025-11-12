#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[201], xr;
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	xr = a[1];
	sort(a + 1, a + 1 + n*m, cmp);
	int w = -1;
	for(int i = 1; i <= n*m; i++) {
		if(a[i] == xr) {
			w = i;
			break;
		}
	}
/*	for(int i = 1; i <= n*m; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
*/
	int cnt = 1;
	while(1) {
		if(w-n <= 0) {
			cout << cnt << " ";
			if(cnt % 2 == 0) {
				//cout << "test: cnt = " << cnt << " w = " << w << endl;
				cout << n - w + 1 << endl;
				return 0;
			} else {
				cout << w << endl;
				return 0;
			}
		} else {
			//cout << "test in else: cnt = " << cnt << " w = " << w << " w - n = " << w-n << endl;
			w -= n;
			cnt++;
		}
	}
	return 0;
}
