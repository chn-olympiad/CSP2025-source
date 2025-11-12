#include<bits/stdc++.h>
using namespace std;
struct peo{
	int a, b, c;
}a[500005];
int t, n, ans, sum1, sum2, sum3, b[500005];
void dfs(int x, int v){
	if(v + b[n] - b[x - 1] <= ans)return;
	if(x == n + 1){
		ans = max(ans, v);
		return;
	}
	if(sum1 + 1 <= n / 2){
		sum1++;
		dfs(x + 1, v + a[x].a);
		sum1--;
	}
	if(sum2 + 1 <= n / 2){
		sum2++;
		dfs(x + 1, v + a[x].b);
		sum2--;
	}
	if(sum3 + 1 <= n / 2){
		sum3++;
		dfs(x + 1, v + a[x].c);
		sum3--;
	}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		cin >> n;
		ans = -1e9;
		sum1 = sum2 = sum3 = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d %d %d", &a[i].a, &a[i].b, &a[i].c);
			b[i] = b[i - 1] + max({a[i].a, a[i].b, a[i].c});
		}
		dfs(1, 0);
		printf("%d\n", ans);
	}
	return 0;
} 