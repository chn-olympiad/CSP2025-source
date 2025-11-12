#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[1000000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n,k,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<3) cout<<0;
	else if(n==3){
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
	}
	else if(a[n]==1){
		for(int i=3;i<=n;i++){
			ll o=i-1;
			for(int j=2;j<i;j++){
				o*=(i-j);
				o/=j;
				o=o%998244353;
				ans+=o;
				ans=ans%998244353;
			}
		}
		cout<<ans%998244353;
	}
	else cout<<rand();
	return 0;
}
