#include<bits/stdc++.h>
#define int long long
using namespace std;
int mod = 998244353;
int n,maxn,a[50005],ans;
int qkm(int a,int b){
	int res =1;
	while(b){
		if(b&1) res = res * a % mod;
		a=a*a%mod;
		b >>= 1;
	}
	return res;
}
void dfs(int dep,int sum,int mxn){
	if(dep == n){
		if(sum > 2*mxn) ans++;
		return; 
	}
	dfs(dep+1,sum+a[dep+1],max(mxn,a[dep+1]));
	dfs(dep+1,sum,mxn);
}
signed main(){
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i],maxn =max(maxn,a[i]);
	if(maxn == 1){
		cout << ((qkm(2,n)-n*(n-1)%mod+mod) %mod-n-1 + mod) % mod << "\n";
		return 0;
	}
	else{
		dfs(0,0,0);
		cout << ans << "\n";
	}
	return 0;
}

