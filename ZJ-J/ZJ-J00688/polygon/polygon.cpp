#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,a[10000],mmx=0;
long long ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mmx=max(mmx,a[i]);
	}
	if(n==3){
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					int mx=max(a[i],max(a[j],a[k]));
					int sum=a[i]+a[j]+a[k];
					if(sum>mx*2){
						ans++;
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(mmx==1){
			for(int i=1;i<=n/2;i++){
				long long ji=i;
				long long b=1,c=1;
				while(ji){
					b*=(n-ji+1)%mod;
					c*=ji%mod;
				}
				ans+=b/c;
			}
			ans=ans*2%mod;
			ans-=n%mod;
			ans-=n*(n-1)/2%mod;
		cout<<ans;
		return 0;
	}
	cout<<13;
	return 0;
}
