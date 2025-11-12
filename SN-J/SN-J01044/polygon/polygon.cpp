#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[5005],ans,mod = 998244353,dp[2][50005][4][2],now = 1,nxt;
void add(int &x,int y){
	x = (x + y) % mod;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if(n <= 500){
		m = 50000;
	}
	else{
		m = 5000;
	}
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	dp[nxt][0][0][0] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= m;j++){
			if(dp[nxt][j][0][0]){//目前选了0条边 
				add(dp[now][j][0][0],dp[nxt][j][0][0]);
				add(dp[now][j + a[i]][1][0],dp[nxt][j][0][0]);
			}
			if(dp[nxt][j][1][0]){//目前选了1条边
				add(dp[now][j][1][0],dp[nxt][j][1][0]);
				add(dp[now][j + a[i]][2][0],dp[nxt][j][1][0]);
			} 
			if(dp[nxt][j][2][0]){//目前选了2条边 
				add(dp[now][j][2][0],dp[nxt][j][2][0]);
				add(dp[now][j + a[i]][3][0],dp[nxt][j][2][0]);
				if(j + a[i] > 2 * a[i]){
					add(dp[now][j + a[i]][3][1],dp[nxt][j][2][0]);
				}
			} 
			if(dp[nxt][j][3][0]){//目前选了至少3条边 
				add(dp[now][j][3][0],dp[nxt][j][3][0]);
				add(dp[now][j][3][1],dp[nxt][j][3][1]);
				add(dp[now][j + a[i]][3][0],dp[nxt][j][3][0]);
				if(j + a[i] > 2 * a[i]){
					add(dp[now][j + a[i]][3][1],dp[nxt][j][3][0]);
				}
			}
		}
		swap(now,nxt);
		for(int j = 0;j <= m;j++){
			for(int k = 0;k < 4;k++){
				for(int l = 0;l < 2;l++){
					dp[now][j][k][l] = 0;
				}
			}
		}
	}
	for(int i = 0;i <= m;i++){
		add(ans,dp[n & 1][i][3][1]);
	}
	cout << ans;
	return 0;
}
