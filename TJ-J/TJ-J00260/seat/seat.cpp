#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	int n,m;
	cin>>n,m;
	int a[n][m];
	int l=0;
	int b1=0;
	int c[n*m];
	for(int i=0;i<n*m;i++)
	{
		cin>>c[i];
		if(i==0)
		{
			b1=c[i];
		}
	}
	for(int i=0;i<n*m;i++)
	{
		for(int j=i;j<n*m;j++)
		{
			if(c[i]<c[j])
			{
				int k=c[i];
				c[i]=c[j];
				c[j]=k;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			c[l]=a[i][j];
			l++;
			if(a[i][j]==b1)
			{
				cout<<n<<" "<<m;
				return 0;
			}
		}
	}
	
	return 0;
}
