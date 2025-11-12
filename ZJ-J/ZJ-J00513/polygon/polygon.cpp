#include <bits/stdc++.h>
using namespace std;
int n, a[5005], ans, mx = -1,pre[5005];
void dfs(int u,int v,int sum,int k){
	if(u > n){
		if(v >= 3 && sum > 2 * k){
			ans ++;
		}return;
	}
	if(sum + pre[n]-pre[u] <= mx*2)return ;
	dfs(u+1,v,sum,k);
	dfs(u+1,v+1,sum+a[u], max(k,a[u]));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		mx = max(mx,a[i]);
		pre[i] = pre[i-1]+a[i];
	}
	dfs(1,0,0,-1);
	cout << ans;
	return 0;
}
