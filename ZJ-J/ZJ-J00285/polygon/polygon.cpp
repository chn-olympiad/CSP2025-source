#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353; 
const int N = 5005;
int n, a[N], pw[N], t[N], ans;
bool cmp(int x, int y){
	return x > y;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	pw[0] = 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		pw[i] = pw[i-1] * 2;
		pw[i] %= MOD;
	}
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= a[1]; j++){
			if(j - a[i] < 0){
				ans += (pw[n-i] * t[j]) % MOD;
				ans %= MOD;
			}else{
				t[j-a[i]] += t[j];
				t[j-a[i]] %= MOD;
			}
		}
		t[a[i]]++;
		t[a[i]] %= MOD;
	}
	cout << ans << "\n";
	return 0;
}