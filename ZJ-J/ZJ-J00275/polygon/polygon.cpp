#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,i,j,k,ans;
int a[5100];
int f[5100][5100];
int c(int r,int l){
	int p=1,i;
	for(i=l;i<=r;i++) p*=i;
	for(i=1;i<=r-l+1;i++) p/=i;
	return p/2;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if(a[n]==1&&n>500){
    	for(i=3;i<=n;i++) ans=(ans+c(n,i))%mod;
    	cout<<ans;
    	return 0;
	}
    for(i=1;i<=n;i++){
		f[i][a[i]-1]=1;
    	for(j=a[i];j<=5000;j++)
    		for(k=1;k<=i-1;k++) f[i][j]=(f[i][j]+f[k][j-a[i]])%mod;
	}
	for(i=3;i<=n;i++)
		for(j=a[i];j<=5000;j++)
			for(k=1;k<=i-1;k++) ans=(ans+f[k][j])%mod;
	cout<<ans;
	return 0;
}