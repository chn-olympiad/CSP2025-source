#include<bits/stdc++.h>
using namespace std;
int mp[1200010],f[500010],a[500010],xr[500010],las[500010],n,k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		xr[i]=a[i]^xr[i-1];
	}
	mp[0]=1;
	for(int i=1;i<=n;i++)
	{
		las[i]=mp[xr[i]^k];
		mp[xr[i]]=i+1;
	}
	for(int i=1;i<=n;i++)
	{
		if(las[i])
		f[i]=max(f[las[i]-1]+1,f[i-1]);
		else
		f[i]=f[i-1];
	}
	printf("%d",f[n]);
	return 0;
}
