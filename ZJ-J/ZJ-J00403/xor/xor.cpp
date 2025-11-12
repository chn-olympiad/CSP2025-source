#include <bits/stdc++.h>
using namespace std;
int n,k,x,a,c[500005],p[500005],f[500005];
queue<int> d[1050000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		c[i]=c[i-1]^a;
		d[c[i]].push(i);
	}
	for(int i=1;i<=n;i++)
	{
		x=c[i-1]^k;
		while(!d[x].empty())
		{
			if(d[x].front()<i)
				d[x].pop();
			else break;
		}
		if(d[x].empty())p[i]=n+1;
		else p[i]=d[x].front();
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=max(f[i],f[i-1]);
		f[p[i]+1]=f[i]+1;
	}
	printf("%d",max(f[n],f[n+1]));
	return 0;
}