#include <bits/stdc++.h>
using namespace std;

long long n,ans,mod = 998244353;
long long a[5050],f[5050];

bool cmp(long long x,long long y){
	return x > y;
}

long long dfs(long long x,long long maxn,long long sum,long long cnt){
	if (sum > maxn * 2 && cnt >= 3){
		return pow(2,n - x);
	}
	if (x > n){
		return 0;
	}
	return dfs(x + 1,maxn,sum + a[x + 1],cnt + 1) + dfs(x + 1,maxn,sum,cnt);
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (long long i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1,cmp);
	for (long long i = 1;i <= n;i++){
		ans += dfs(i,a[i],a[i],1);
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}
