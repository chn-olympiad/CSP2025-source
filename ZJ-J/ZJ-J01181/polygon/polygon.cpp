#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int a[5005],b[5005],f[5005];
int pl(int n,int m){
	int sum=1;
	for(int i=n;i>=m+1;i--){
		sum=(sum*i)%mod;
	}
	for(int i=n-m;i>=1;i--){
		sum=(sum/i)%mod;
	}
	return sum;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3]) cout<<1<<endl;
		else cout<<0<<endl;
		return 0;
	}
	bool aa=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			aa=0;
			break;
		}
	}
	if(aa){
		int ans=0;
		for(int i=3;i<=n;i++){
			ans+=pl(n,i)%mod;
		}
		cout<<ans<<endl;
	}
	else{
		if(a[1]+a[2]>a[3]) f[3]=1;
		for(int i=1;i<=n;i++){
			b[i]=(a[i]+b[i-1])%mod;
		}
		for(int i=3;i<=n;i++){
			if(a[i]<b[i-1]){
				int lrx=0;
				for(int j=3;j<=i;j++) lrx+=pl(i,j);
				f[i]=(f[i-1]+lrx)%mod;
			}
			else{
				f[i]=f[i-1];
			}
		}
		cout<<f[n]<<endl;
	}
	return 0;
}
