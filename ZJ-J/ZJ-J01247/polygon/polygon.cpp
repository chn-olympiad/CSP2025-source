#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5005],ans,mod=998244353;
void dfs(int p,int gen,int zuichang,int zongchang){
	if(p>n){
		if(zongchang>zuichang*2&&gen>=3)ans=(ans+1)%mod;
		return ;
	}
	for(int i=0;i<=1;i++){
		if(i==0)dfs(p+1,gen,zuichang,zongchang);
		else dfs(p+1,gen+1,max(zuichang,a[p]),zongchang+a[p]);
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
