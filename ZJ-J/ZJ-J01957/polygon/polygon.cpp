#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0)
#define ll long long
constexpr int maxn = 5e3+3,mod = 998244353;
int n;
int a[maxn];
int ans;
void dfs(int k,int com,int exp,int maxs,int sum){
	if(com == exp){
		if(maxs*2 < sum) (ans += 1) %= mod;
		return;
	}
	for(int i = k+1;i <= n;i++)
		dfs(i,com+1,exp,max(maxs,a[i]),sum+a[i]);
}
ll base[maxn];
void init(){
	for(int i = 1;i <= n;i++)
		base[i] = base[i-1]*i%mod;
}
int C(int n,int m){
	return base[m]/base[m-n]/base[n];
}
int main(){
	IOS;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	if(n > 20){
		init();
		int ans = 0;
		for(int i = 3;i <= n;i++) (ans += C(i,n)) %= mod;
		cout << ans;
	}else{
		for(int i = 3;i <= n;i++)
			dfs(0,0,i,0,0);
		cout << ans;
	}	
	return 0;
}
