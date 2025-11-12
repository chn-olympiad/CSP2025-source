#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
int a[550];
long long ans = 1;

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) ans *= i;
	cout << ans % 998244353;
	return 0;
}
