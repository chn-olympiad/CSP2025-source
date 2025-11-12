#include<bits/stdc++.h>>
using namespace std;
int n,m,x=0,sum=0,abc=0,w=0,mus=0;
int a[15][15],b[230];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	x=m*n;
	for(int i=1;i<=x;i++)
	{
		cin>>b[i];
	}
	w=b[1];
	for(int i=1;i<=x;i++)
	{
		for(int j=i;j<=x;j++)
		{
			if(b[i]<b[j])
			{
				sum=b[i];
				b[i]=b[j];
				b[j]=sum;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(i%2!=0)
		{
			for(int j=1;j<=n;j++)
			{
				abc++;
				if(w==b[abc])
				{
					cout<<i<<" "<<j;
					return 0;
				}
				a[i][j]=b[abc];
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				abc++;
				if(w==b[abc])
				{
					cout<<i<<" "<<j;
					return 0;
				}
				a[i][j]=b[abc];
			}
		}
	}
}
