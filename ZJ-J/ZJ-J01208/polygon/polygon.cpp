#include <iostream>
#include <algorithm>

int n, a[5005];
long long sum[5005][5005];
long long ans = 0;

void dfs(int id, int add, int maxx, int cnt){
	if(id == n and cnt >= 3 and add > 2 * maxx){
		ans++;
		ans %= 998244353;
		return ;
	}
	if(id == n)
		return ;
	dfs(id + 1, add + a[id + 1], std::max(maxx, a[id + 1]), cnt + 1);
	dfs(id + 1, add, maxx, cnt); 
}

signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	bool sp = 1;
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d", &a[i]);
		if(a[i] != 1)
			sp = 0;
	}
	
	if(sp == 0){
		dfs(1, a[1], a[1], 1);
		dfs(1, 0, 0, 0);		
	}
	else{
		for(int i = 0;i <= n;i++){
			sum[i][0] = sum[i][i] = 1;
			for(int j = 1;j <= i;j++)
				sum[i][j] = (sum[i - 1][j - 1] + sum[i - 1][j]) % 998244353;
		}
		for(int i = 3;i <= n;i++)
			ans = (ans + sum[n][i]) % 998244353;
	}
	printf("%lld", ans);
	return 0;
}