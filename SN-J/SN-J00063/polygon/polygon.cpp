//SN-J00063
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,s[5005],k[25],cnt,sum,big,mod=998244353,ans;
ll qpow(int n,int m){
	ll s=1,t=n;
	while(m){
		if(m&1) s=(s*t)%mod;
		t=(t*t)%mod;
		m>>=1;
	}
	return (s+mod)%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>s[i];
	sort(s+1,s+n+1);
	if(n<=20){
		for(ll i=7;i<1<<n;i++){
			sum=cnt=0;
			for(ll j=i;j!=0;j/=2){
				k[++cnt]=j%2;
				if(j%2==1) sum++;
			}
			if(sum<3) continue;
			sum=big=0;
			for(ll j=cnt;j;j--){
				ll x=cnt-j+1;
				if(k[cnt-j+1]==1) big=max(big,cnt-j+1),sum+=s[x];
			}
			if(sum>2*s[big]) ans++;
		}
		cout<<ans;
	}
	else cout<<(qpow(2,n)%mod-1-n-(n*(n-1)/2)%mod)%mod;
	return 0;
}
