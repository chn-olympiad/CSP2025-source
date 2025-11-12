#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2*1e5+10;
ll n,k;
ll a[N],sum[N],dp[N];
vector<pair<ll,ll>>vv;
bool flA=true,flB=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=1)flA=false;
		if(a[i]>1)flB=false;
		sum[i]=sum[i-1] xor a[i];
	}
	if(k==0&&flA==true){
		printf("%lld",n/2);
		return 0;
	}
	else if(flB==true){
		ll ans=0;
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1)ans++;
			}
			printf("%lld",ans);
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==0)ans++;
				if(a[i]==1&&a[i+1]==1){
					ans++;
					i++;
				}
			}
			printf("%lld",ans);
		}
		return 0;
	}
	else{
		ll p=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i;j<=n;j++){
				if((sum[j] xor sum[i-1])==k){
					p++;
					i=j;
					break;
				}
			}
		}
		printf("%lld",p);
	}
	return 0;
}