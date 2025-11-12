#include<bits/stdc++.h>

using namespace std;
//ll
const int N = 1e3 + 10;
int T;
int n;
int a[N][3], ans, sum;
int s[3];
void work(int k) {
	if (k == n + 1) {
		ans = max(ans, sum);
		return;
	}
	for (int i = 0; i < 3; i ++) {
		if (s[i] + 1 <= n / 2) {
			s[i] ++;
			sum += a[k][i];
			work(k + 1);
			s[i] --;
			sum -= a[k][i];
		}
	}
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while(T --) {
		cin >> n;
		for (int i = 1; i <= n; i ++) {
			for (int j = 0; j < 3; j ++) {
				cin >> a[i][j];
			}
		}
		ans = 0;
		sum = 0;
		work(1);
		cout << ans << endl;
	}
	
	return 0;
}
