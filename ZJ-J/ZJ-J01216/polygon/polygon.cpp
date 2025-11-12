#include <bits/stdc++.h>
using namespace std;
long long n,a[5005];
long long MOD = 998244353;
long long dfs(long long now,long long sum,long long ver,long long step){
	long long ans=0;
	if(step>=3){
		if(ver*2<sum){
			ans++;
		}
	}
	for(long long i = now+1;i<=n;i++){
		ans+=dfs(i,sum+a[i],max(ver,a[i]),step+1)%MOD;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	for(long long i = 1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	cout << dfs(0,0,0,0);
	return 0;
}
