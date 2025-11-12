#include<bits/stdc++.h>
using namespace std;
long long n,m,a[110],a1,b=0,ans=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a1;
	a[1]=a1;
	for(int i=2;i<=n*m;i++)
		cin>>a[i];
	sort(a+1,a+n*m+1);	
	for(int i=1;i<=n;i++)
	{
		if(b==0)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[n*m-ans]==a1)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				ans++;
			}	
			b=1;
		}
		else
		{
			for(int j=m;j>=1;j--)
			{
				if(a[n*m-ans]==a1)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				ans++;
			}	
			b=0;
		}
	}
	return 0;
}
