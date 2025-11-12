#include <bits/stdc++.h>
using namespace std;
const int N = 10 + 5;
int n, m;
int a[N];
bool cmp(int x, int y) {
	return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int nn = n * m, s = a[1];
	sort(a + 1, a + nn + 1, cmp);
	int cnt = 1;
	for (int i = 1; i <= nn; i++) {
		if (a[i] != s) cnt++;
		else break;
	}
	int x, y;
	if (cnt % m != 0) {
		x = cnt / m + 1;
	} else {
		x = cnt / m;
	}
	if (x % 2 == 1) {
		if (cnt % m != 0) y = cnt % m;
		else y = m;
	} else {
		if (cnt % m != 0) y = m - (cnt % m) + 1;
		else y = 1;
	}
	cout << x << ' ' << y;
	return 0;
}
