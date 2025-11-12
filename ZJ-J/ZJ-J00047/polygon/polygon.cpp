#include<bits/stdc++.h>
using namespace std;
int n,a[5100],sum[5100],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		cout<<sum[i]<<endl;
	}
	for(int k=3;k<=n;k++){
		for(int i=1;i+k-1<=n;i++){
			int j=i+k-1;
			if(a[j]*2<sum[j]-sum[i-1]) ans=(ans+1)%998244535;
		}
	}
	cout<<ans;
}
