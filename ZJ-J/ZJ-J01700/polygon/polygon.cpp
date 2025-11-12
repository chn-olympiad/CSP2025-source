#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,i,j,k,l,a[5001],fct[5001],nfct[5001],f[201][101][4],sum,max_;
int qp(int x,int y)
{
	int sum=1;
	while(y)
	{
		if(y&1)
		  sum=sum*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return sum;
}
int C(int x,int y)
{
	return fct[x]*nfct[y]%mod*nfct[x-y]%mod;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	   cin>>a[i];
	fct[0]=1;
	for(i=1;i<=n;i++)
	   fct[i]=fct[i-1]*i%mod;
	nfct[n]=qp(fct[n],mod-2);
	for(i=n-1;i>=0;i--)
	   nfct[i]=nfct[i+1]*(i+1)%mod;
	for(i=1;i<=n;i++)
	   max_=max(max_,a[i]);
	for(i=3;i<=n;i++)
	   sum=(sum+C(n,i))%mod;
	if(max_==1)
	{
		cout<<sum;
		return 0;
	}
	f[0][0][0]=1;
	for(i=1;i<=n;i++)
	   for(j=2*max_-a[i];j>=0;j--)
	      for(k=0;k<=max_;k++)
	         for(l=0;l<=3;l++)
	            f[j+a[i]][max(k,a[i])][min(l+1,3ll)]=(f[j+a[i]][max(k,a[i])][min(l+1,3ll)]+f[j][k][l])%mod;
	for(i=0;i<=max_;i++)
	   for(j=0;j<=2*i;j++)
	      sum=(sum-f[j][i][3]+mod)%mod;
	cout<<sum;
	return 0;
}
