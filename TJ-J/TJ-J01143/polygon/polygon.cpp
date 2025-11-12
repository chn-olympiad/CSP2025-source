#include<iostream>
#include<algorithm>
int n;
int a[500000];
int ans, max_, sum;
void dfs(int x){
	for(int i = x; i < n; i ++){
		int t = max_;
		max_ = std::max(max_, a[i]);
		sum += a[i];
		if(sum > 2 * max_){
			ans++;
			if(ans >= 998244353) ans -= 998244353;
		}
		dfs(i + 1);
		sum -= a[i];
		max_ = t;
	}
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		scanf("%d", &a[i]);
	}
	dfs(0);
	printf("%d", ans);
	return 0;
}
//RP++ >_< AC!!!!!! noWA!!! AK!!!
//RP++ >_< AC!!!!!! noWA!!! AK!!!
//RP++ >_< AC!!!!!! noWA!!! AK!!!
//RP++ >_< AC!!!!!! noWA!!! AK!!!
//dfs?
//dfs!!!!!!
