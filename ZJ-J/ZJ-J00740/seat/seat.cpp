#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],k=1,i,j,ans=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])k++;
	}
	for(i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(j=1;j<=n;j++)
			{
				ans++;
				if(ans==k)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
			
		}
		if(i%2==0)
		{
			for(j=n;j>=1;j--)
			{
				ans++;
				if(ans==k)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
