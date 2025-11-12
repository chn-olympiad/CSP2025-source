#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10, M = 2e2 + 10, MOD = 1e9 + 7;
bool cmp(int q, int h) {
	return q > h;
}
int a[M];
signed main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int k = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	
	int now = 1;
	bool flag = 1;
	for (int j = 1; j <= m; j++) {
		if (flag) {
			for (int i = 1; i <= n; i++) {
//				printf("-%d %d %d %d ", j, i, now, a[now]);
				if (a[now] != k) {
					now++;
				} else {
					cout << j << " " << i << '\n';
					return 0;
				}
			}
//			cout << '\n';
		} else {
			for (int i = n; i >= 1; i--) {
//				printf("#%d %d %d %d ", j, i, now, a[now]);
				if (a[now] != k) {
					now++;
				} else {
					cout << j << " " << i << '\n';
					return 0;
				}
			}
//			cout << '\n';
		}
		
		flag = !flag;
	}
	return 0;
}

