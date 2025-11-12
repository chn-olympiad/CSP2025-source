#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,mod=998244353;
typedef long long ll;
int n,a[N],pre[N],ans;
bool op=1;
bool get(int x){
	int res=0;
	while(x){
		x-=x&(-x);
		++res;
		if(res>=3)return 1;
	}
	return 0;
}
bool check(int x){
	int cnt=0,mx=0;
	for(int i=0;i<n;++i){
		if(x&(1<<i))
			cnt+=a[i+1],mx=max(mx,a[i+1]);
	}
	return cnt>2*mx;
}
ll qpow(ll a,int b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		b>>=1;a=a*a%mod;
	}
	return res;
}
ll query(int x){
	ll ans=0,sum[N],inv[N];
	sum[0]=inv[0]=1;
	for(ll i=1;i<=x;++i){
		sum[i]=sum[i-1]*i%mod;
		inv[i]=qpow(sum[i],mod-2);
	}
	for(int i=3;i<=x;++i)
		ans=(ans+sum[n]*inv[i]%mod*inv[n-i]%mod)%mod;
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);	
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if(a[i]!=1)op=0;
	}
	if(op){
		cout<<query(n);
	}
	else if(n<=25){
		int L=1<<n;
		for(int S=1;S<L;++S){
			if(get(S)&&check(S))++ans;
			if(ans>mod)ans-=mod;
		}
		cout<<ans;
	}
	return 0;
}
