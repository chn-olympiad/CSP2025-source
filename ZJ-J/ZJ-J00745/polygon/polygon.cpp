#include <bits/stdc++.h>
using namespace std;
long long a[5555],n,fl,mod=998244353,ans;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) fl=1;
	}
	if(fl==0){
		ans=1;
		for(int i=1;i<=n;i++) ans=ans*2%mod;
		ans=(ans-1-n-n*(n-1)/2+mod)%mod;
		cout<<ans;
		return 0;
	}
	for(int i=1;i<pow(2,n);i++){
		long long cnt=0,x=i,mx=0,sum=0;
		for(int j=1;j<=n;j++){
			if(x%2==1){
				cnt++;
				sum+=a[j];
				mx=max(mx,a[j]);
			}
			x/=2;
		}
		if(cnt>=3&&sum>mx*2) ans++;
	}
	cout<<ans;
	return 0;
}
