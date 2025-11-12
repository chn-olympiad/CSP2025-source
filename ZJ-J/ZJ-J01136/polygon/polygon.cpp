#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10,mod = 998244353;
int n,a[N],res[N],ans;
void check(int len){
	int sum = 0,ma = -1;
	for(int i = 1;i <= len;i++){
		sum += a[res[i]];
		ma = max(ma,a[res[i]]);
	}
	if(sum > ma * 2)ans = (ans + 1) % mod;
}
void dfs(int pos){
	if(pos > 3){
		check(pos - 1);
	}
	for(int i = res[pos - 1] + 1;i <= n;i++){
		res[pos] = i;
		dfs(pos + 1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n <= 25){
		dfs(1);
		cout << ans;
		return 0;
	}
	long long res = 0;
	for(int i = 3;i <= n;i++){
		long long k = 1;
		for(int j = n;j >= i;j--){
			k = (k * j) % mod;
		}
		res = (res + k) % mod;
	}
	cout << res;
	return 0;
}