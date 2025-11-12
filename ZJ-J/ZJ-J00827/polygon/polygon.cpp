#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
ll a[5050],n;
ll AN[5050],ANUM[5050];
ll ans;
void dfs(ll now,ll num){
	for(ll x=now+1;x<=n;x++){
		if(num>a[x])ans=(ans+1)%MOD;
		dfs(x,num+a[x]);
	}
}
void H(){
	ANUM[1]=1;
	for(ll i=2;i<=n;i++){
		ANUM[i]=(ANUM[i-1]*i)%MOD;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	ll maxn=-1;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		maxn=max(maxn,a[i]);
	}
	if(n>20&&maxn==1){
		H();
		AN[1]=n;
		for(ll i=2;i<=n;i++){
			AN[i]=AN[i-1]*(n-i+1)%MOD;
		}
		for(ll i=3;i<=n;i++){
			ans=(ans+(AN[i]/ANUM[i]))%MOD;
		}
		printf("%lld",ans);
	}
	else{
		sort(a+1,a+1+n);
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				for(ll q=j+1;q<=n;q++){
					if(a[i]+a[j]+a[q]>2*a[q])ans=(ans+1)%MOD;
					dfs(q,a[i]+a[j]+a[q]);
				}
			}
		}
		printf("%lld",ans);
	}
	return 0;
}