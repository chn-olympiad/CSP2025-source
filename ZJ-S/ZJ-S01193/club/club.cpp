#include<bits/stdc++.h>
using namespace std;
int T, n, a[100010][5], b[100010];
long long ans;
void dfs(int i){
	if(i == n + 1){
		int c1 = 0, c2 = 0, c3 = 0;
		for(int j = 1; j <= n; j++){
			c1 += b[j] == 1, c2 += b[j] == 2, c3 += b[j] == 3;
		}
		long long cnt = 0;
		if(max(max(c1, c2), c3) <= n / 2){
			for(int j = 1; j <= n; j++){
				cnt += a[j][b[j]];
			}
			ans = max(ans, cnt);
		}
		return;
	}
	for(int j = 1; j <= 3; j++){
		b[i] = j;
		dfs(i + 1);
	}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	for(; T--; ){
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				scanf("%d", &a[i][j]);
			}
		}
		ans = 0;
		dfs(1);
		printf("%lld\n", ans);
	}
	return 0;
}
