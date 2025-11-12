#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5;
ll tw[21];
ll n , k , a[N] , maxv ;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k ;
	for(ll i=1;i<=n;i++)
		cin >> a[i] ;
	for(ll l=1;l<=n;l++){
		for(ll r=l;r<=n;r++){
			ll ans=r-l+1;
			if(ans<maxv)
				continue;
			ll x=(a[l]!=a[l+1]);
			for(ll i=l+2;i<=r;i++){
				x=(x!=a[i]);
			}
			if(x==k)
				maxv=max(maxv,ans);
		}
	}
	cout << maxv ; 
}
