#include<bits/stdc++.h>
#define ll long long
#define N 505
#define M 998244353
using namespace std;
ll b[N],c[N];
bool a[N];
ll power(ll x,ll y){
	x%=M;
	ll ans=1;
	while(y){
		if(y&1)ans=ans*x%M;
		x=x*x%M,y>>=1;
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	s=" "+s;
	for(ll i=1;i<=n;i++)a[i]=s[i]-'0';
	for(ll i=1;i<=n;i++)cin>>b[i];
	if(n<=10){
		for(ll i=1;i<=n;i++)c[i]=i;
		ll ans=0;
		do{
			ll cnt=0;
			for(ll i=1;i<=n;i++)if(!a[i]||cnt>=b[c[i]])cnt++;
			if(cnt<=n-m)ans++;
		}while(next_permutation(c+1,c+n+1));
		cout<<ans%M;
		return 0;
	}
	if(n==m){
		bool l=1;
		for(ll i=1;i<=n;i++)l&=(a[i])&(b[i]!=0);
		if(!l)cout<<"0";
		else{
			ll ans=1;
			for(ll i=1;i<=n;i++)ans=ans*i%M;
			cout<<ans;
		}
		return 0;
	}
//	bool fl=1;
//	ll cnt=0;
//	for(ll i=1;i<=n;i++)fl&=a[i],cnt+=(b[i]==0);
//	
//	
	return 0;
}
