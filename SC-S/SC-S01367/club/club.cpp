#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
struct node{
	int x, id;
};
node a[N][5];
int n, ans = -1;
bool cmp(node a, node b){
	return a.x > b.x;
}
void dfs(int u, int cnti, int cnt1, int cnt2, int cnt3, int tot){
	if(cnti == 1) cnt1++;
	if(cnti == 2) cnt2++;
	if(cnti == 3) cnt3++;
	if(cnt1 > n / 2 || cnt2 > n / 2 || cnt3 > n / 2){
		return ;
	}
	if(u > n){
		ans = max(tot, ans);
		return ;
	}
	for(int i = 1; i <= 3; i++){
		dfs(u + 1, a[u][i].id, cnt1, cnt2, cnt3, tot + a[u][i].x);
	}
}
void solve(){
	scanf("%d", &n);
	int d[N];
	memset(d, 0, sizeof d);
	ans = -1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 3; j++){
			scanf("%d", &a[i][j].x);
			a[i][j].id = j;
		}
		sort(a[i] + 1, a[i] + 3 + 1, cmp);
	}
	dfs(0, 0, 0, 0, 0, 0);
	printf("%d\n", ans);
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int _; scanf("%d", &_);
	while(_--){
		solve();
	}
	return 0;
}