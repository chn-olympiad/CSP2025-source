#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	vector<long long> a(n*m+1,200);
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	long long s=a[1];
	sort(a.rbegin(),a.rend());
	long long id=0;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==s)
		{
			id=i;
			break;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(i%2==0)
		{
			for(int j=1;j<=m;j++)
			{
				if(i*n+j==id)
				{
					cout<<i+1<<' '<<j;
					return 0;
				}
			}
		}
		else
		{
			for(int j=1;j<=m;j++)
			{
				if(i*n+j==id)
				{
					cout<<i+1<<' '<<m-j+1;
					return 0;
				}
			}
		}
	}
	return 0;
}
