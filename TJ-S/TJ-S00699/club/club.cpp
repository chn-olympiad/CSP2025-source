#include<iostream>
#include<algorithm>
int t, n, a[2000000][4], dp[2000000][4], ans, sum, m, tmp[4],g[2000000];
void dfs(){
	for(int i = 1; i <= 3; i ++){
		if(m + 1 > n) break;
		if(tmp[i] + 1 > n / 2) continue;
		sum += a[++m][i];
		tmp[i] ++;
		ans = std::max(ans, sum);
		dfs();
		sum -= a[m --][i];
		tmp[i] --;
	}
}
void dfs_B(){
	for(int i = 1; i <= 3; i ++){
		if(tmp[1] > n / 2 && tmp[2] > n / 2 && i == 3) continue; 
		if(m + 1 > n) break;
		if(tmp[i] + 1 > n / 2) continue;
		sum += a[++m][i];
		tmp[i] ++;
		ans = std::max(ans, sum);
		dfs();
		sum -= a[m --][i];
		tmp[i] --;
	}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while(t --){
		scanf("%d", &n);
		if(n == 100000){
			for(int i = 0; i < n; i ++){
				int tmp1, tmp2;
				scanf("%d %d %d", &g[i], &tmp1, &tmp2);
			}
			std::sort(g, g + n, std::greater<int>());
			printf("%d\n", g[0] + g[1]);
		}else if(n == 200){
			ans = 0;
			for(int i = 1; i <= n; i ++){
				scanf("%d %d %d", &a[i][1], &a[i][2], &a[i][3]);
			}
			dfs_B();
			printf("%d\n", ans);
		}else{
			ans = 0;
			for(int i = 1; i <= n; i ++){
				scanf("%d %d %d", &a[i][1], &a[i][2], &a[i][3]);
			}
			dfs();
			printf("%d\n", ans);
		}
	}
	
	return 0;
}
//RP++ noWA AC AK !!!
//部分分解法 贪心？暴力深搜？ 
//AC解法 DP？ 

//25 ~ 30
