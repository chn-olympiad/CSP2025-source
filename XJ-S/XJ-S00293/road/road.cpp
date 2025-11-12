#include<bits/stdc++.h>
using namespace std;
unsigned long long int n,m,k,a[15][10005],c[1000000005],s,u,v,w,x,b[10005][10005];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,j;
	cin>>n>>m>>k;
	
	for(i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		b[u][v]=w;
		s+=w;
	}
	for(j=1;j<=k;j++)
	{
		cin>>c[j];
		for(i=1;i<=n;i++)
		{
			cin>>a[j][i];
		}
	}
	for(x=1;x<=k;x++)
	{
		if(c[x]>s)
		{
			continue;
		}
    	for(i=1;i<=n;i++)
	    {
		    for(j=1;j<=n;j++)
	    	{
		    	if(b[i][j]>a[x][i]+a[x][j]&&b[i][j]!=0)
		    	{
		    		s-=b[i][j];
		    		s+=c[x];
		    		s+=a[x][j];
		    		b[i][j]=0;
		    	}
		    	
	    	}
    	}
    }
    cout<<s;
	return 0;
 } 
