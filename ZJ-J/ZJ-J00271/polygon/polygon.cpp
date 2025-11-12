#include<bits/stdc++.h>
using namespace std;

const int N = 5050, MOD = 998244353;

int n, a[N], ans, c[N][N];

void dfs(int i, int k, int maxx, int sum){
	if(i > n){
		if(k >= 3 && maxx * 2 < sum)
			ans = (ans + 1) % MOD;
		return;
	}
	dfs(i + 1, k, maxx, sum);
	dfs(i + 1, k + 1, max(a[i], maxx), sum + a[i]);
}


void init(){

	for(int i = 0; i <= N; i ++){
		c[i][0] = 1;
		for(int j = 1; j <= i; j ++)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
	}
		
}

int main(){
	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	
	cin >> n;
	for(int i = 1; i <= n; i ++)
		scanf("%d", &a[i]);
	
	
	if(n > 20){
		init();
		for(int i = 3; i <= n; i ++)
			ans = (ans + c[n][i]) % MOD;
		printf("%d\n", ans);
		return 0;
	}
	
	dfs(1, 0, 0, 0);
	
	printf("%d\n", ans);

	
	return 0;
}