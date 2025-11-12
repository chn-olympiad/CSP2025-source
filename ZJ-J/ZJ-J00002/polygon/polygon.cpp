/* ¶à±ßÐÎ */
                                                                       
#include <bits/stdc++.h>
#define regint register int
using namespace std;
const int MOD = 998244353;
int cnt = 0;

int n;
int a[5005];
void dfs(int dep, int sum, int siz, int mxi){
	if(dep == mxi){
		if(siz >= 3 && sum > a[mxi]*2)
			cnt = (cnt + 1) % MOD;
		return;
	}
	dfs(dep+1, sum+a[dep], siz+1, mxi);
	dfs(dep+1, sum, siz, mxi);
}

int main(){
	int tmp;
	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(regint i = 1; i <= n; i++)
		scanf("%d", a+i);
	
	sort(a+1, a+n+1);
	for(regint i = 3; i <= n; i++){
		dfs(1, a[i], 1, i);
	}
	printf("%d", cnt);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
