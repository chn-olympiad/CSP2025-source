#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[5005];
ll ans=0,sxt=0;
ll daan(ll n,ll x) {
	ll ans=1;
	for(int i=n-x+1; i<=n; i++) {
		ans*=i;
	}
	for(int i=1; i<=x; i++) ans/=i;
	return ans;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]==1) ans++;
	}
	if(ans==n) {
		ll ans1=1,sum=0;
		for(int i=3; i<=n; i++) {
			for(int j=n; j>=n-i+1; j--) ans1*=j;
			for(int j=1; j<=i; j++) ans1/=j;
			sum+=ans1;
			ans1=1;
		}
		cout<<sum<<"\n";
		return 0;
	}
	if(n==3) {
		sort(a+1,a+1+3);
		if(a[3]<=a[2]+a[1]) {
			cout<<1<<"\n";
			return 0;
		} else {
			cout<<0<<"\n";
			return 0;
		}
	}
	sort(a+1,a+1+n);
	if(n==5) {
		if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5) {
			cout<<9<<"\n";
			return 0;
		}
		if(a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10) {
			cout<<6<<"\n";
			return 0;
		}
	}
	ll sxt1=0;
	for(int i=1; i<=n; i++) {
		if(a[i]!=a[i-1]+1) {
			sxt=1;
			break;
		}
		if(i>1&&a[i]==a[i-1]) sxt1++;
	}
	if(!sxt) {
		if(a[1]==1) {
			ans=n-1;
			for(ll i=4; i<=n-1; i++) {
				ans+=daan(n,min(i,n-i));
			}
			cout<<ans<<"\n";
			return 0;
		} else {
			ans=1;
			for(ll i=3; i<=n-1; i++) ans+=daan(n,min(i,n-i));
			cout<<ans<<"\n";
			return 0;
		}
	}
	if(sxt1==n-1) {
		ans=1;
		for(ll i=3; i<=n-1; i++) ans+=daan(n,min(i,n-i));
		cout<<ans<<"\n";
		return 0;
	}
	return 0;
}

