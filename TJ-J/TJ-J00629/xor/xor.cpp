#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,k,a[N],dp[N],f[N][N];
long long xr(int x,int y){
	long long tmp1=f[x][y-1],tmp2=a[y],p=1,ans=0;
	while (tmp1 || tmp2){
		ans+=p*((tmp1%2)^(tmp2%2));
		p*=2;
		tmp1/=2;
		tmp2/=2;
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i],f[i][i]=a[i];
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			f[i][j]=xr(i,j);
	dp[1]=(a[1]==k);
	for (int i=2;i<=n;i++)
		for (int j=i;j>=1;j--)
			if (f[j][i]==k){
				dp[i]=dp[j-1]+1;
				break;
			}
	long long maxn=-1;
	for (int i=1;i<=n;i++)
		maxn=max(maxn,dp[i]);
	cout<<maxn;
	return 0;
}
