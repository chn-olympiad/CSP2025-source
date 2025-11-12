#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m,p[100000],x=0,q[100000];
    cin>>n>>m;
    int a[m][n],b[m][n];
    for(int i=1;i<=n*m;i++)
    {
    	cin>>p[i];
    	q[i]=p[i];
	}
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=n*m;j++)
		{
			if(p[j]<p[i])
			{
				swap(p[j],p[i]);
			}
		}
	}
	for(int j=1;j<=m;j++)
	{
		x++;
		if(x%2==1)
		{
			for(int i=1;i<=n;i++)
	        {
		        a[j][i]=p[i+(j-1)*n];
		        b[j][i]=i+(j-1)*n;
	        }
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				a[j][i]=p[n-i+1+(j-1)*n];
				b[j][i]=n-i+1+(j-1)*n;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==q[1])
			{
				cout<<i<<" "<<j;
				break;
			}
		}
	}
    return 0;
}
