#include<bits/stdc++.h>
using namespace std;
int main(){
	typedef long long ll;
	ll n,p=0,inf=998244353,s,mx;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	for (ll i=0;i<n-2;i++){
		mx=max(a[i],a[i+1]);
		s=a[i]+a[i+1];
		for (ll j=i+2;j<n;j++){
			s+=a[j];
			if (a[j]>mx) mx=a[j];
			if (s>2*mx) p++;
		}
	}
	cout<<p%inf;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
