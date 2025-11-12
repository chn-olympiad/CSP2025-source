#include<iostream>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[110],c,b[10][10]={0},o=0; 
	cin>>n>>m;
	c=n*m;
	for(int i=0;i<c;i++)
	{
		cin>>a[i];
	}
	o=a[1];
	for(int i=0;i<c;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(a[j]<a[j+1])
			{
				int x=a[j+1];
				a[j+1]=a[j];
				a[j]=x;
			 } 
		}
	}
	int q=0;
	for(int i=0;i<=m;i++)
	{
		if(i%2==0)
		{
			for(int j=n;j>=0;j--)
			{
				b[j][i]=a[q];
				q=q+1;
			}
		}
		if(i%2==1)
		{
			for(int j=0;j<=n;j++)
			{
				b[j][i]=a[q];
				q=q+1;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(b[i][j]==o)
			{
				cout<<i<<" "<<j;
				
			}
		}

	}
	return 0;
}
