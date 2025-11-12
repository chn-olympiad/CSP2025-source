#include<bits/stdc++.h>
using namespace std;
int a[1000],b[1000];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,cl;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
    	cin>>a[i];
	}
	cl=a[1];
	sort(a+1,a+(n*m)+1);
	for(int i=1;i<=n*m;i++)
	{
		b[i]=a[n*m-i+1];
	}
    for(int i=1;i<=n*m;i++)
	{
		a[i]=b[i];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i%2!=0)
			{
				if(a[i*n+j-n]==cl)
				{
					cout<<i<<" "<<j;
				}
			}
			if(i%2==0)
			{
				if(a[i*n+j-n]==cl)
				{
					cout<<i<<" "<<n-j+1;
				}
			}
		}
	}
	return 0;
}