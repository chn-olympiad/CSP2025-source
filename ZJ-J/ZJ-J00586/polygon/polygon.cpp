#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
const int N = 5e3 + 10;
const int M = 1e6 + 10; 
int a[N];
int val[M];
int n;
signed main () {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i];
	}
	sort (a + 1, a + n + 1);
	int sum = a[1] + a[2];
	val[a[1]]++; val[a[2]]++; val[a[1] + a[2]]++;  val[0] = 1;
	int ans = 0;
	for (int i = 3; i <= n; i ++ ) {
		for (int j = a[i] + 1; j <= sum; j ++ ) {
			val[j] %= mod;
			ans += val[j];
			ans = ans % mod;
		}	
		for (int j = sum; j >= 0; j -- ) {
			val[j + a[i]] += val[j];
			val[j + a[i]] %= mod;
		}
		sum += a[i];
	} 
	cout << ans % mod;
} 
