#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5010],f[5010][5010],g[5010][5010],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=5001;j>=0;j--) f[i][j]=f[i-1][j];
		for(int j=5001;j>=5001-a[i];j--) (f[i][5001]+=f[i-1][j])%=mod;
		for(int j=5000;j>=a[i];j--) (f[i][j]+=f[i-1][j-a[i]])%=mod;
		for(int j=5001;j>=0;j--) g[i][j]=(g[i][j+1]+f[i][j])%mod;
	}
	for(int i=1;i<=n;i++) ans=(ans+g[i-1][a[i]+1])%mod;
	cout<<ans<<endl;
	return 0;
}
