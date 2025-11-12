#include <bits/stdc++.h>

using namespace std;
int a[510];
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	long long ans = 1;
	for(int i = 0; i < n; ++ i) cin >> a[i];
	for(int i = n; i >= 1; -- i){
		ans *= i;
		ans %= 998244353;
	}
	cout << ans;
	return 0;
}

