#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
ll n=0,a[5005]={},ans=0;
bool flag=true;
void dfs(ll x,ll m,ll sum,ll ma){
	if (x==n+1&&m>=3&&sum>2*ma){
		ans++;
		ans%=mod;
	}
	if (x>n+1){
		return ;
	}
	dfs(x+1,m,sum,ma);
	dfs(x+1,m+1,sum+a[x],max(ma,a[x]));
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if (a[i]!=1){
			flag=false;
		}
	}
	if (flag==false){
		dfs(1,0,0,0);
	}
	else{
		for (int i=3;i<=n;i++){
			ll tot=1;
			for (int j=n-i+1;j<=n;j++){
				tot=tot*j;
			}
			for (int j=1;j<=i;j++){
				tot=tot/j;
			}
			ans+=tot;
			ans%=mod;
		}
	}
	printf("%lld",ans);
	return 0;
}
