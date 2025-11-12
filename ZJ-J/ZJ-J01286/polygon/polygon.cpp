#include <bits/stdc++.h>
using namespace std;
int n,i,a[5010],sum[5010],ma[5010][5010],ans,j;;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];sum[i]=sum[i-1]+a[i];
	}
	for(i=1;i<=n;i++){
		ma[i][i]=a[i];
		for(j=i+1;j<=n;j++)
			ma[i][j]=max(ma[i][j-1],a[j]);
	}
	for(i=3;i<=n;i++)
		for(j=1;j<=n-i+1;j++)
			if((sum[j+i-1]-sum[j-1])>(2*ma[j][j+i-1]))ans=(ans+1)%998244353;
	cout<<ans%998244353;
	return 0;
}