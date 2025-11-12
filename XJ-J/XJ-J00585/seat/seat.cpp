#include<bits/stdc++.h>
using namespace std;
long long int i,n,m,a[105],j;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=m*n;i++)
	{
		cin>>a[i];
		if(i==1)
		{
			j=a[i];
		}
	}
	sort(a+1,a+1+n,greater<int>());
	if(n==1)
	for(i=1;i<=m;i++)
	{
		if(a[i]==j)
		{
			cout<<i<<" "<<1;
		}
	}
	else
		if(m==1)
		{
			for(i=1;i<=n;i++)
			{
				if(a[i]==j)
				{
					cout<<1<<" "<<i;
				}
			}
		}
	if(n==2&&m!=1)
	{
		if(a[1]==j)
		cout<<1<<" "<<1;
		else
		{
			if(m%2==1)
			{
				cout<<m<<" "<<n;
			}
			else
			{
				cout<<m<<" "<<1;
			}
		}
	}
	return 0;
}
