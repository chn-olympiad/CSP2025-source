#include<bits/stdc++.h>

using namespace std;
int g[11][11],c[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a;
	cin>>n>>m;
	
	for(int i=0;i<n*m;i++)
	{
		cin>>c[i];
	}
	a=c[0];
	for(int i=0;i<n*m;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(c[i]>c[j])
				swap(c[i],c[j]);			
		}
	}
	int sum=0;
	
	for(int i=0;i<n*m;i++)
	{	
		if((i/m)%2!=0)
		{
			for(int k=i;k<i+m;k++)
			{
				for(int j=k;j<i+m;j++)
				{
					if(c[j]<c[k])
						swap(c[k],c[j]);
				}
			}
			
			i+=3;
		}
	}
	
			
	sum=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			g[j][i]=c[sum];
			sum++;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(g[i][j]==a)
				cout<<j+1<<" "<<i+1;
		}
	}
	return 0;	
} 


