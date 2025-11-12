#include<bits/stdc++.h>
using namespace std;
const int maxN = 5e3 + 5;
const long long MOD = 998244353;
long long n, ans;
long long aj[maxN];
void dfs(int pos, long long mus, long long madlx, int k){
	if(pos > n){
		if(mus > madlx * 2 && k > 2){
			ans++;
			ans%=MOD;
		}
		return;
	}
	dfs(pos + 1, mus, madlx, k);
	if(aj[pos] > madlx){
		madlx = aj[pos];
	}
	dfs(pos + 1, mus + aj[pos], madlx, k+1);
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> aj[i];
	}
	dfs(1, 0, 0, 0);
	cout << ans << endl;
	return 0;
}
