#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[5010];
int vis[5010];
ll num[5010];
ll ans = 0;
int f = 1;
ll mod = 998244353; 
void solve(){
	num[1] = 1;
	num[0] = 1;
	for(int i = 2;i <= n;i++){
		num[i] = num[i-1]*i;
		num[i] %= mod;
	}
//	for(int i = 1;i <= n;i++){
//		cout<<num[i]<<endl;
//	}
	ll sum = 1,c = 1,ans2 = 0;
	for(int i = 3;i <= n;i++){
		ll p = num[n]/num[i];
		ans2 += p/num[n-i];
		ans2%= mod;
	}
	cout<<ans2<<endl;
	return ;
}
void dfs(int x,int r,int t,ll sum,int maxn){
	if(x == r+1){
		if(sum > 2*maxn){
			ans++;
			ans %= mod;
		}
		return ;
	}
	for(int i = t;i <= n;i++){
		if(vis[i])	continue;
		vis[i] = 1;
		dfs(x+1,r,i,sum+a[i],max(maxn,a[i]));
		vis[i] = 0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(a[i] != 1)	f = 0;
	}
	if(f && n > 20){
		solve();
		return 0;
	}
	for(int i = 3;i <= n;i++){
		dfs(1,i,1,0,0);
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

