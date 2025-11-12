#include<bits/stdc++.h>
#define ll long long
using namespace std;
char at_10_43_am;
const int mod=998244353;
int n,a[5005],maxn;
ll f[5005][5050],ans;
ll quickpow(ll x,ll y){
	ll res=1;
	while(y){
		if(y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
char I_AK_CSP_J;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	//printf("%d\n",&I_AK_CSP_J-&at_10_43_am);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+n+1);
	for(int j=0;j<=maxn;j++) f[0][j]=1;
	for(int j=0;j<a[1];j++) f[1][j]=1;
	for(int j=a[1];j<=maxn;j++) f[1][j]=2;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=maxn;j++){
			if(j>=a[i]) f[i][j]=(f[i-1][j-a[i]]+f[i-1][j])%mod;
			else f[i][j]=f[i-1][j];
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<=10;j++) cout<<f[i][j]<<" ";
//		cout<<"\n";
//	}
	int i=1,j=0;
	while(i<=n){
		ll cnt=1;
		while(i<=n&&a[i]==a[i+1]){
			i++;
			cnt++;
		}
		ll tmp=quickpow(2,j);
		//xuan 1
		ans=(ans+cnt*((tmp-f[j][a[i]]+mod)%mod)%mod)%mod;
		//xuan 2
		if(cnt>=2) ans=(ans+(cnt*(cnt-1)/2)*((tmp-1+mod)%mod)%mod)%mod;
		if(cnt>2) ans=(ans+tmp*((quickpow(2,cnt)-1-cnt-(cnt*(cnt-1)/2)+mod+mod)%mod)%mod)%mod;
		j=i;
		i++;
	}
	cout<<ans<<"\n";
	return 0;
}
