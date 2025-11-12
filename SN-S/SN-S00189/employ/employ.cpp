#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long m, n, cnt, ans;
string s;
int arr[1010];

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> m >> n >> s;
	for (int i = 0; i < n; i ++){
		cnt += s[i] - '0';
	}
	for (int i = 0; i < n; i ++){
		cin >> arr[i]; 
	}
	if (cnt == n){
		ans = 1;
		for (int i = 1; i <= n; i ++){
			ans *= i;
			ans %= mod;
		}
		cout << ans;
		return 0;
	}
	if (n == m) {cout << 0; return 0;}
	
	return 0;
} 
