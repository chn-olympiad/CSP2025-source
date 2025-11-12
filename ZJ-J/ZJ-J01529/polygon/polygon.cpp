#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10, mod = 998244353;
int n, cnt = 3, a[N], b[N];
long long ans;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	b[1] = a[1], b[2] = a[2], b[3] = a[1] + a[2];
	for(int i = 3; i <= n; i++){
		long long sum = 0;
		for(int j = 1; j <= cnt; j++)
			if(b[j] > a[i]) sum++;
		//cout << a[i] << " " << cnt << " " << sum << "\n";
		ans = (ans + sum) % mod;
		int t = cnt;
		for(int j = 1; j <= t; j++)
			b[++cnt] = b[j] + a[i];
		b[++cnt] = a[i];
	}
	cout << ans;
	return 0;
}

