#include<bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define FINISH
int l[5010], n, ans;
void dfs(int x, int sdn, int mxs2, int sds){
	if(sdn >= 3){
		if(mxs2 < sds){
			ans = (ans + 1) % MOD;
		}
	}
	for (int i = x - 1; i >= 1; i--){
		dfs(i, sdn + 1, mxs2, sds + l[i]);
	}
}
int qp(int x){
	int a = 2, ans = 1;
	while(x){
		if(x & 1)ans = ans * a % MOD;
		a = a * a % MOD;
		x >>= 1;
	}
	return ans % MOD;
}
int main(){
#ifdef FINISH
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
#endif
	scanf ("%d", &n);
	int maxinai = 0;	
	for (int i = 1; i <= n; i++){
		scanf ("%d", l + i);
		maxinai = max(l[i], maxinai);
	}
	if(maxinai == 1){
		ans = 1 + ((n * (n + 1) % MOD) / 2);
		ans = (qp(n) - ans + MOD) % MOD;
	}else{
		sort(l + 1, l + n + 1);
		for (int i = n; i >= 3; i--){
			dfs(i, 1, 2 * l[i], l[i]);
		}	
	}
	printf("%d", ans);
	return 0;
}
