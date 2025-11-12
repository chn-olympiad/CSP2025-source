#include <bits/stdc++.h>
using namespace std;
int a[500050];
int qz[500050];
int f(int a , int b) {
	int x = 1 << 21;
	int ans = 0;
	for(int i = 21; i >= 0; i--) {
		int a1 = a / x;
		int b1 = b / x;
		a1 %= 2;
		b1 %= 2;
		ans += (a1 != b1) << i;
		x >>= 1;
	}
	return ans;
}
int n , maxn = -1 , sum = 0 , k;
int cnt = 0 , ans = 0;
int main() {
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) 
		cin >> a[i];
	qz[1] = a[1];
	for(int i = 2; i <= n; i++)
		qz[i] = qz[i - 1] ^ a[i];
	for(int i = 1; i <= n; i++) {
		for(int j = cnt; j < i; j++) {
			if(f(qz[j] , qz[i]) == k) {
				ans++;
				cnt = i;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
