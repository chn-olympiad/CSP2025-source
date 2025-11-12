#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],s[5005],ans,len,sum,p,maxx,mod=998244353;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(long long i=1; i<=(1<<n)-1; i++) {
		len=0;
		p=i;
		for(long long j=1; j<=n; j++) {
			s[j]=p%2;
			p/=2;
			if(s[j]==1)len++;
		}
		if(len<3)continue;
		sum=0,maxx=0;
		for(long long j=1;j<=n;j++){
			if(s[j]==1){
				sum+=a[j];
				maxx=max(maxx,a[j]);
			}
		}
		if(maxx<sum-maxx){
			ans++;
			ans=ans%mod;
		}
	}
	cout<<ans%mod;
	return 0;
}
