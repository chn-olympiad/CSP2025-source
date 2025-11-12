#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
const Int MaxN = 5e3+10;
const Int Mod = 998244353;
Int n;
Int res = 0;
Int a[MaxN];
Int b[MaxN];
Int c[MaxN][MaxN];
void dfs(Int p, Int cnt, Int root){
	
	if(p < 1) return;
	dfs(p-1,cnt,root);
	dfs(p-1,cnt+a[p],root);
	if(cnt+a[p] > a[root]*2){
		res ++;
		res %= Mod;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(Int i = 1; i <= n; i ++){
		scanf("%lld", &a[i]);
	}
	sort(a+1,a+n+1);
	if(n < 30){
		for(Int i = 3; i <= n; i ++){
			dfs(i-1,a[i],i);
		}
	} else {
		for(Int i = 1; i <= n; i ++){
			c[i][1] = 1, c[i][i] = 1;
			for(Int j = 2; j < n; j ++){
				c[i][j] = c[i-1][j-1]+c[i-1][j];
				c[i][j] %= Mod;
			}
		}
		for(Int i = 1; i <= n; i ++){
			res += c[i][n];
			res %= Mod;
		}
	}
	
	printf("%lld\n", res);
	return 0;
}

/*






*/
