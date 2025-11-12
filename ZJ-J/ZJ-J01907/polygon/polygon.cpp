#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[50008];
ll b[50008];
const int mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    ll n,sum=0;
    cin>>n;
    for(ll i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	ll ans=0;
	for(ll m=3;m<=n;m++){
		int l=1,r=0;
		while(r<n){
			r=l+m-1;
			ll ma=a[r];
			ll s=b[r]-a[l];
			if(2*ma>=s)l++;
			else ans=(ans+1)%mod,l++;
		}
	}
	cout<<(2*ans)%mod;
	return 0;
}
