#include<bits/stdc++.h>
using namespace std;
long long nxt,n,a[5001],f[5005][5],ans,M=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;++i)
	  cin>>a[i];
	sort(a+1,a+1+n);
	f[0][0]=1;
	for(long long i=1;i<=n;++i)
	  for(long long j=5001;j>=0;--j)
	  {
	  	nxt=min(5001ll,j+a[i]);
	  	if(j>a[i])
	  	  f[nxt][4]=((f[nxt][4]+f[j][3])%M+f[j][2])%M;
	  	f[nxt][3]=((f[nxt][3]+f[j][2])%M+f[j][3])%M;
	  	f[nxt][2]=(f[nxt][2]+f[j][1])%M;
	  	f[nxt][1]=(f[nxt][1]+f[j][0])%M;
	  }
	for(long long i=0;i<=5001;++i)
	  ans=(ans+f[i][4])%M;
	cout<<ans;
	return 0;
}