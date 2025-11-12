#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010],f[500010],ma[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0;i<=n;i++)
		f[i]=0;
	for(int i=0;i<=n;i++)
		ma[i]=0;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	f[0]=0;
	if(a[1]==k)f[1]=1;
	else  f[1]=0;
	ma[1]=f[1];
	int z=0;
	for(int i=2;i<=n;i++)
	{
		z=0;
		for(int j=i;j>0;j--)
		{
			z=(z^a[j]);
			if(z==k)
			f[i]=max(f[i],ma[j-1]+1);
		}
		ma[i]=max(ma[i-1],f[i]);
	}
	printf("%d",ma[n]);
	return 0;
}
