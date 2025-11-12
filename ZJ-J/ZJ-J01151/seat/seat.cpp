#include <bits/stdc++.h>
using namespace std;
const int N = 200;
int n, m, mid, x, y, idx, a[N];
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++) cin >> a[i];
	mid = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i ++){
		if (mid == a[i]){
			idx = i;
			break;
		}
	}
	x = (idx - 1) / n;
	y = (idx - 1) % n + 1;
	if (x % 2 == 1) y = n - y + 1;
	cout << x + 1 << " " << y;
	return 0;
}
