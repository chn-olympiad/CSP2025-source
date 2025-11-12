//9:20 passed all samples&&AK,csp-s rp++
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],f[5005][5005],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	f[0][0]=1;
	for(int i=1;i<=2;i++)
	for(int j=0;j<=5001;j++){
		(f[i][j]+=f[i-1][j])%=mod;
		(f[i][min(j+a[i],5001)]+=f[i-1][j])%=mod;
	}
	for(int i=3;i<=n;i++){
		for(int j=a[i]+1;j<=5001;j++)ans=(ans+f[i-1][j])%mod;
		for(int j=0;j<=5001;j++){
		(f[i][j]+=f[i-1][j])%=mod;
		(f[i][min(j+a[i],5001)]+=f[i-1][j])%=mod;
	}
	}
	printf("%d\n",ans);
	return 0;
}
