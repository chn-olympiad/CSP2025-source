#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
int n,a[100001],ans;
void dfs(int i,int s,int ma,int l){
	if(i == n+1){
		if(s > ma*2 && l >= 3)ans = (ans+1)%mod;
		return;
	}
	dfs(i+1,s,ma,l);
	dfs(i+1,s+a[i],max(ma,a[i]),l+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	dfs(1,0,0,0);
	cout << ans%mod;
	return 0;
} 
