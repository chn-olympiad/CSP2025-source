#include<bits/stdc++.h>
using namespace std;
#define CSP
#define max3(a, b, c) max(max(a, b), c)
#define a1(i) a[i].d1
#define a2(i) a[i].d2
#define a3(i) a[i].d3
int n, hn;
struct stu{
	int d1, d2, d3;
}a[100010];
int ans;
void dfs(int x, int sum1, int sum2, int sum3, int sum){
	if(x == n + 1){
		if(sum > ans)ans = sum;
		return ;
	}
	if(sum1 < hn)
		dfs(x + 1, sum1 + 1, sum2, sum3, sum + a1(x));
	if(sum2 < hn)
		dfs(x + 1, sum1, sum2 + 1, sum3, sum + a2(x));
	if(sum3 < hn)
		dfs(x + 1, sum1, sum2, sum3 + 1, sum + a3(x));
	return;
}
int main(){
#ifdef CSP
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
#endif
	int t;
	scanf ("%d", &t);
	while(t--){
		ans = 0;		
		scanf ("%d", &n);
		hn = n / 2;
		for (int i = 1; i <= n; ++i){
			scanf("%d %d %d", &a1(i), &a2(i), &a3(i));
		}
		dfs(1, 0, 0, 0, 0);
		printf("%d\n", ans);
	}
	return 0;
}