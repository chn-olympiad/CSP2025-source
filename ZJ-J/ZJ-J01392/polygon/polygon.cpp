#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int N=5005;
const int INF=0x3f3f3f3f;
int a[N];
ll fac[N],inv[N],jv[N];
void com_init(int n){
	inv[1]=1;
	for(int i=2;i<=n;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	fac[0]=jv[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=fac[i-1]*i%mod;
		jv[i]=jv[i-1]*inv[i]%mod;
	}
}
ll com(ll n,ll m){
	if(n<m||m<0) return 0;
	return fac[n]*jv[n-m]%mod*jv[m]%mod;
}
ll pw[N],pre[N];
int T[N];
ll f[N*2],g[N*2];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    scanf("%d",&n);
    int sum=0;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i],T[a[i]]++;
    sort(a+1,a+n+1);
    if(a[n]==1){
    	com_init(n);
    	ll ans=0;
    	for(int i=3;i<=n;i++) ans=(ans+com(n,i))%mod;
    	printf("%lld\n",ans);
    	return 0;
	}
	if(n<=20){
	    ll tot=0;
	    for(int i=0;i<1<<n;i++){
	    	int sum=0,mx=0,u=0;
	    	for(int j=0;j<n;j++){
	    		if(i>>j&1){
	    			sum+=a[j+1];
	    			if(a[j+1]>mx) mx=a[j+1],u=j+1;
				}
			}
			if(sum>2*mx) tot++,T[u]++;
		}
		printf("%lld\n",tot);
		return 0;
	}
	pw[0]=1;
	for(int i=1;i<=n;i++) pw[i]=pw[i-1]*2%mod;
	g[0]=f[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=a[i];j<=2*a[n];j++) f[j]=(f[j]+g[j-a[i]])%mod;
		for(int j=1;j<=2*a[n];j++) g[j]=f[j];
	}
	for(int i=1;i<=2*a[n];i++) pre[i]=(pre[i-1]+f[i])%mod;
	ll ans=0;
	for(int i=3;i<=n;i++){
		ans=(ans+pw[i-1]-pre[a[i]]+T[a[i]]-1)%mod;
	}
	ans=(ans%mod+mod)%mod;
	printf("%lld\n",ans);
    return 0;
}

