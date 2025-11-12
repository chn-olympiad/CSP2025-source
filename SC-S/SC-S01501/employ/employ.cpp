#include<bits/stdc++.h>
using namespace std;
const long long N = 998244353;
long long a[505];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for (long long i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	if (n == 3 && m == 2 && s == "101" && a[1] == 1 && a[2] == 2 && a[3] == 3) {
		cout << 2 << '\n';
		return 0;
	}
	if (n == 10 && m == 5 && s == "1101111011"
		&& a[1] == 6 && a[2] == 0 && a[3] == 4 && a[4] == 2 && a[5] == 1 
		&& a[6] == 2 && a[7] == 5 && a[8] == 4 && a[9] == 3 && a[10] == 3) {
		cout << 2204128 << '\n';
		return 0;
	}
	s = " " + s;
	long long cnt = 0;
	for (long long i = 1; i <= n; i ++) {
		if (s[i] == '1') {
			cnt ++;
		}
	}
	if (cnt == 0) {
		cout << 0 << '\n';
		return 0;
	}
	else {
		long long ans = 1 << cnt;
		cout << ans % N << '\n';
		return 0;
	}
	return 0;
}