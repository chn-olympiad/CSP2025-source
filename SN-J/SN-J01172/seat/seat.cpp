#include<bits/stdc++.h>
using namespace std;
int seat[15][15],c[1005],cnt=0;
int n,m,rc;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out ","w",stdout);
	cin>>n;
	cin>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>c[i];
	}
	rc=c[0];
	for(int i=0;i<n*m;i++)
	{
		for(int j=i+1;j<n*m;j++)
		{
			if(c[i]<c[j])
			{
				int t=c[j];
				c[j]=c[i];
				c[i]=t;
			}
		}
	}
	for(int i=0;i<n*m;i++)
	{
		for(int j=i;j<n*m;j++)
		{
			if(j-i==(m-1)&&(j>(m-1)&&j!=(n*m)))
			{
				swap(c[i],c[j]);
			}
			if(j==m*n)
			{
				break;
			}
		}
	}
	
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<m+1;j++)
		{
			
			seat[i][j]=c[cnt++];			
		}
	}
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<m+1;j++)
		{
			if(seat[i][j]=c[0])
			{
				cout<<seat[i][j];
			}
		}
	}
	return 0;
} 
