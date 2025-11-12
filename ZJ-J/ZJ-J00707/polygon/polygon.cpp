#include<bits/stdc++.h>
using namespace std;
const long long N=5005,mod=998244353;
long long n,sum,ans,a[N],s[N*N/10];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	s[0]=1;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		for(long long j=sum;j>a[i];j--)ans=(ans+s[j])%mod;
		sum+=a[i];
		for(long long j=sum;j>=a[i];j--){
			s[j]=(s[j]+s[j-a[i]])%mod;
		}
	}
	cout<<ans;
	return 0;
}
