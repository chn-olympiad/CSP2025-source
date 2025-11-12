#include<iostream>
using namespace std;
int n, m, cnt;
int a[110];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i ++) cin >> a[i];
	for(int i = 1; i <= n * m; i ++)
		cnt += (a[i] >= a[1]);
	int c = (cnt + n - 1) / n;
	int k = cnt % n, r = 0;
	if(!k) k = n;
	if(c & 1) r = k;
	else r = n - k + 1;
	cout << c << " " << r << '\n';
	return 0;
}