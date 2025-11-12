#include<bits/stdc++.h>
using namespace std;
int a[500005], vis[500005];
int n, k;
long long cnt;
void dfs(int x, long long num){
	if(x == n - 1){
		return ;
	}
	if(num == k) cnt++;
	if(!vis[x]){
		vis[x] = 1;
		dfs(x + 1, num ^= a[x]);
		vis[x] = 0;
	}
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++) dfs(i, a[i]);
	cout << cnt;
	return 0;
}

