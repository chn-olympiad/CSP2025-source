#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
long long n,a[5005],dp[5005],cnt,sum[5005],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	sum[0]=1;
	for(int i=1;i<=n;++i){
		//ÏÈdp
		if(i!=1){
			cnt=0;
			for(int j=a[i]+1;j<=5001;++j){
				cnt=(cnt+sum[j])%mod;
			}
			for(int j=1;j<i;++j){
				if(a[j]>a[i]){
					cnt=(cnt+mod-1)%mod;
				}
			}
			ans+=cnt;
		}
		for(int j=5001;j>=0;--j){
			sum[min(j+a[i],5001*1LL)]=(sum[min(j+a[i],5001*1LL)]+sum[j])%mod;
		}
	}
	cout<<ans%mod;
}
