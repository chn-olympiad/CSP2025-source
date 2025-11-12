#include<bits/stdc++.h>
using namespace std;
int n;
int a[100010];
int sum[100010];
int vis[100010];
int ans = 0;
int q[100010];
void dfs(int x, int sum_all, int dep){
	if(dep >= 3){
		if(sum_all > 2*a[x]){
			ans++;
//			for(int i = 0; i < dep; i++){
//				cout << q[i] << " ";
//			}
//			cout << endl;
		}
	}
	for(int i = x+1; i <= n; i++){
		q[dep] = a[i];
		if(dep >= 2){
			if(sum_all+a[i] <= 2*a[i]){
				for(int j = i+1; j <= n; j++){
					q[dep+1] = a[j];
					dfs(j, sum_all+a[i]+a[j], dep+2);
				}
			}else{
				dfs(i, sum_all+a[i], dep+1);
			}
		}else{
			dfs(i, sum_all+a[i], dep+1);
		}
	}
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	sum[0] = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+1+n);
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i-1]+a[i];
	}
	dfs(0, 0, 0);
	cout << ans;
	return 0;
}