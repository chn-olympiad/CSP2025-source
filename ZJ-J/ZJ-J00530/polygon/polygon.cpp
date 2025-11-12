#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5005],ans,cnt[11000],yi,suma;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i],suma+=a[i];
	sort(a+1,a+1+n);
	cnt[0]=1;
	for(int i=1;i<=n;++i){
		yi=yi*2%mod;
		for(int j=11000;j>=0;--j){
			if(j+a[i]<=11000) cnt[j+a[i]]=(cnt[j+a[i]]+cnt[j])%mod;
			else yi+=cnt[j],yi%=mod;
		}
		for(int j=a[i]*2+1;j<=11000;++j){
			ans+=cnt[j];
			ans%=mod;
		}
		ans=(ans+yi)%mod;
	}
	cout<<ans;
	return 0;
}
