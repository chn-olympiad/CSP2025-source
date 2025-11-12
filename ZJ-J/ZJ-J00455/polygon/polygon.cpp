#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e4 + 100;
const int mod = 998244353;
int a[N], s[N];
int n;
int cnt;
void dfs(int x, int h, int sum, int max, int p){
	if(x == h){
		if(sum > 2 * max)
			cnt = (cnt + 1) % mod;
		return;
	}
	for(int i = p; i <= n; i++){
		dfs(x + 1, h, sum + a[i], a[i], i + 1);
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	
	for(int i = 3; i <= n; i++)
		dfs(0, i, 0, -1, 1);
	cout << cnt;
	return 0;
}
