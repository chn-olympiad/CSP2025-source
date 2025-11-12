#include <bits/stdc++.h>
using namespace std;
long long n, a[5002], f = 1, ans;
long long b[5003];
/*int quick(int a, int b){
	int ans = 1, c = 1;
	while (b & 1){
		c *= a;
		ans = ans * c % 998244353;
		b &= (b - 1);
	}
	return ans;
}*/
void dfs(long long x, long long y, long long z){
	if (x > z){
		return;
	}
	if (y > a[z]){
		b[z] += pow(2, z - x);
		return;
	}
	dfs(x + 1, y, z);
	dfs(x + 1, y + a[x], z);
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (a[i] != 1){
			f = 0;
		}
	}
	if (n == 3){
		sort(a, a + 3);
		if (a[0] + a[1] > a[2]){
			cout << 1;
		}else{
			cout << 0;
		}
		return 0;
	}
	sort (a + 1, a + n + 1);
	for (int i = 3; i <= n; i++){
		dfs(1, 0, i);
		ans += b[i];
		ans %= 998244353;
	}
	cout << ans << endl;
	return 0;
}
