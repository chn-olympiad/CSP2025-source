#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
ll a[5005],cnt[10005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n;
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	ll ans=0,res=0;
	cnt[0]++,cnt[a[1]]++,cnt[a[2]]++;
	if(a[1]+a[2]>a[3]) ans++;
	
	if(a[1]+a[2]>5000) res++;
	else cnt[a[1]+a[2]]++;
	
	for(ll R=4;R<=n;R++){
		res=res*2%mod;
		for(ll i=5000;i>=5000-a[R-1]+1;i--) res=(res+cnt[i])%mod;
		for(ll i=5000;i>=a[R-1];i--) cnt[i]=(cnt[i]+cnt[i-a[R-1]])%mod;
		for(ll i=a[R]+1;i<=5000;i++) ans=(ans+cnt[i])%mod;
		ans=(ans+res)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
