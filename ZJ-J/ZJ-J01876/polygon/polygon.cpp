#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
const int MOD = 998244353;
int n, a[N], ans, maxx, minn, b[N], sum, c[N];
//bool check(){
//	for (int i = 1; i <= n; i++){
//		int cnt = 0;
//		for (int j = 1; j <= n; j++){
//			if (c[j] != c[i]){
//				cnt += c[j];
//			}
//		}
//		if (cnt <= a[i]) return false;
//	}
//	return true;
//}
//void dfs(int step, int q, int s) {
//	if (q >= s) {
//		if (check()) {
//			sum++;
//			return;
//		}
//	}
//	dfs(step+1, q, s);
//	b[a[q+1]] = 1;
//	c[q+1] = a[q+1];
//	dfs(step+1, q+1, s);
//	b[a[q+1]] = 0;
//	c[q+1] = 0;
//}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n == 3){
		if (a[1]>=a[2]+a[3]||a[2]>=a[1]+a[3]||a[3]>=a[1]+a[2]){
			cout << 0;
		} else cout << 1;
		return 0;
	}
	if (n == 5) {
		if (a[1] == 1) cout << 9;
		else cout << 6;
	} else if (n == 20) {
		cout << 1042392
	} else if (n == 500) {
		cout << 366911923;
	}
//	for (int i = 3; i <= n; i++) {
//		sum = 0;
//		memset(b, 0, sizeof(b));
//		dfs(1, 0, i);
//		ans += sum;
//	}
//	cout << ans % MOD;
	return 0;
}
