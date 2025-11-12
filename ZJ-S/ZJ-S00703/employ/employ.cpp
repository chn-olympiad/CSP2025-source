#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

const int mod = 998244353;

int main(){
	
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
	}
	long long cnt = 0;
	for(int j = m; j <= n; j++){
		long long ans = 1;
		for(int i = n; i >= n - j + 1; i--) ans = ans * i % mod;
		cnt = (cnt + ans) % mod;
	}
	cout << cnt << "\n";
	
	return 0;
}
