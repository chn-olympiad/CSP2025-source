#include<bits/stdc++.h>
using namespace std;
long long ans, p;
int n, m, c;
string s;
int main(){
	std::ios::sync_with_stdio(false);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++){
		cin >> c;
	}
	ans = 1, p = 998244353;
	for (int i = 1; i <= n; i++){
		ans = ans * i % p;
	}
	cout << ans;
 	return 0;
}