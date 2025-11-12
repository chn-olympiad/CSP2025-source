#include<bits/stdc++.h>
using namespace std;
int n,m,i,a[500001],f[500005],g[500001],h[1100000],max_;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	   scanf("%d",a+i);
	for(i=1;i<=n;i++)
	   g[i]=g[i-1]^a[i];
	for(i=0;i<=(1<<20);i++)
	   h[i]=n+1;
	f[n+1]=-1;
	for(i=n;i>=0;i--)
	{
		f[i]=max(f[i+1],f[h[g[i]^m]]+1);
		h[g[i]]=i;
	}
	for(i=0;i<=n;i++)
	   max_=max(max_,f[i]);
	cout<<max_;
	return 0;
}
