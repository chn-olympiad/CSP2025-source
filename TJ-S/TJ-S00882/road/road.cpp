#include<bits/stdc++.h>
using namespace std;
int main ()
{
	freopen("road.in","r",stdin)
	freopen("road.out","w",stdout)
	int a,b,c,x[10000],y[10000],z[10000],d[10000],e[10000],f[10000],g[10000],h[10000],n=0;
	cin>>a>>b>>c;
	for(int i=1;i<=b;i++)
	{
		cin>>x[i]>>y[i]>>z[i];
		for(int j=1;j<=b;j++)
		{
			for(int k=1;k<=b;k++)
			{
				if(z[j]>z[i])
				{
					swap(z[j],z[i]);
				}
			}
		}
		n+=z[i];
		
	}
	return 0;
}
