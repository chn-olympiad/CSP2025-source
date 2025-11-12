#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5010;
const ll mod=998244353;
ll n,a[N];
ll ans=0;
inline ll read(){
	ll s=0,w=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-'){
			w=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<3)+(s<<1)+ch-'0';
		ch=getchar();
	}
	return s*w;
}
ll awa[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(ll i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	if(n==3){
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
	}
	else{
		ll start;
		for(ll i=1;i<=n;i++){
			if(a[i]==1){
				start=i;
				break;
			}
		}
		awa[0]=1,awa[1]=1,awa[2]=2;
		for(ll i=3;i<=n-start+1;i++){
			awa[i]=awa[i-1]*i%mod;
		}
		for(ll i=start+2;i<=n;i++){
			ll k=i-start;
			for(ll j=2;j<=k;j++){
				ans=(ans+(awa[k]/(awa[k-j]*awa[j])))%mod;
			}
		}
		cout<<ans%mod;
	}
	return 0;
}