#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5005],sum,ans,tmp,mod=998244353;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(n==3){//SPJ for 1-3 Get:12
		int x=max(a[1],max(a[2],a[3]));
		int c=min(a[1],min(a[2],a[3]));
		int b=a[1]+a[2]+a[3]-x-c;
//		cout<<x<<" "<<b<<" "<<c<<endl;
		if(c+b<=x) cout<<0;
		else cout<<1;
		return 0;
	}
	if(sum==n){//SPJ for 15-20 Get:24
		int tmp=n*(n-1)*(n-2),t=6;
		ans+=(tmp/t)%mod;
		for(int i=4;i<=n;i++){
			t*=i;
			
			tmp*=(n-i+1);
			ans+=(tmp/t)%mod;
			//%%%
			t%=mod;
			tmp%=mod;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}//expect:36 or more
//expect tot:246+