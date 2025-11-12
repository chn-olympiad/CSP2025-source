#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

const int mod = 998244353;

const int N = 1e6 + 10, M = 1e8 + 10;

void qwq(){
	//fre;
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	LL ans = 1;
	for (int i = 2; i <= n; i ++ ) ans = ans * i % mod;
	cout << ans << endl;
	return;
}



signed main(){
	qwq();
	
	return 0;
}

