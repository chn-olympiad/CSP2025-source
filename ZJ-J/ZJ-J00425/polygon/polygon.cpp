#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long le=5010ll,p=998244353ll;
long long n,ans=0ll;
long long a[le],sum[le],f[le],cnt[le];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1ll;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1ll,a+n+1ll);
	//for(long long i=1ll;i<=n;i++){
	//	sum[i]=sum[i-1ll]+a[i];
	//}
	cnt[0ll]=1ll,cnt[a[1]]=1ll/*,mp[a[2ll]]++,mp[a[1ll]+a[2ll]]=1ll*/;
	//long long sum=2ll;
	//if(a[1]+a[2]<=a[3]){
	//	sum++;
	//}
	f[0ll]=1ll;
	f[1ll]=2ll;
	for(long long i=3ll;i<=n;i++){
		//ll mi=calc(i);
		long long res=0ll;
		for(ll j=a[n]-a[i-1];j>=0ll;j--){
			ll x=j+a[i-1];
			if(x<=a[n]){
				cnt[x]+=cnt[j];
				cnt[x]%=p;
			}
		}
		for(ll j=0;j<=a[i];j++){
			res+=cnt[j];
			res%=p;
		}
		//cout<<res<<endl<<endl;
		f[i-1ll]=(f[i-2ll]*2ll)%p;
		ans+=f[i-1ll]+p-res;
		ans%=p;
		//cout<<ans<<endl;
	}
	//cout<<endl;
	cout<<ans;
	return 0;
} 
