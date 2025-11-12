#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e2 + 10;
int a[N], sum[20][20];
int n, m, x;
bool cmp(int x, int y) {
	return x > y;
}
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i ++) cin >> a[i];
	x = a[1];
	sort(a + 1, a + 1 + n * m, cmp);
	int cnt = 0;
	for(int i = 1; i <= m; i ++) {
		if(i % 2 == 1) {
			for(int j = 1; j <= n; j ++) {
				sum[j][i] = a[++cnt];
			}
		}else{
			for(int j = n; j >= 1; j --) {
				sum[j][i] = a[++cnt];
			}
		}
		
		
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
//			cout << sum[i][j] << " ";
			if(sum[i][j] == x) {
				cout << j << " " << i;
				return 0;
			}
		}
//		cout << "\n";
	}
	return 0;
}
/*
3 4
94 95 96 97 98 99 100 93 92 1 2 3
*/
