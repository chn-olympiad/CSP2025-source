#include<bits/stdc++.h>
using namespace std;
int c[105];
int main() 
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[15][15]={0};
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>c[i];
	}
	int r=c[1];
	for(int i=1;i<=n*m;i++)
	{
		
		if(c[i]<c[i+1])
		{
			int l=0;
			l=c[i+1];
			c[i+1]=c[i];
			c[i]=l;
			l=0;
		}
		
	}
	int sum=0;
	int v=1,o=1;
	for(int i=1;i<=m;i++)
	{
		if(sum%2==0)
		{
			
			for(int j=1;j<=n;j++)
				{
					a[j][i]=c[o];
					o++;
				}
			
		}
		
		if(sum%2==1)
		{
			
			for(int j=n;j>=1;j--)
				{
					a[j][i]=c[o];
					o++;
				}
			
		}
		sum++;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==r)
			{
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
 } 
