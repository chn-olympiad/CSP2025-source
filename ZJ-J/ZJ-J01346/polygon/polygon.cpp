#include <bits/stdc++.h>
using namespace std;
const long long maxn=5005;
const long long mod=998244353;
long long n;
long long sum=0,maxx=-1,cnt=1,cnt1=0;
long long a[maxn];
long long ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=(2<<n)-1;i++){
		cnt=1,cnt1=0,sum=0,maxx=-1;
		long long now=i;
		while(now){
			if(now&1){
				cnt1++;
				sum+=a[cnt];
				maxx=max(maxx,a[cnt]);
			}
			now>>=1;
			cnt++;
		}
		if(cnt1<3)continue;
		if(sum>2*maxx)ans=(ans+1)%mod;
	}
	cout<<ans/2<<"\n";
	return 0;
}
