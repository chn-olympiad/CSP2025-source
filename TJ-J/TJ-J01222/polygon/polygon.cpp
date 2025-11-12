#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

#define int long long

int n,ans;
int a[5005];

void dfs(int dep,int sum = 0,int ma = 0,int j = 0){
	if(dep > n){
		if(sum > ma * 2){
			ans++;
			ans %= 998244353;
		}
		return;
	}
	for(int i = j + 1;i <= dep;i++) dfs(dep + 1,sum + a[i],max(ma,a[i]),i);
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 3;i <= n;i++) dfs(n - i + 1);
	cout << ans;
	return 0;
}
