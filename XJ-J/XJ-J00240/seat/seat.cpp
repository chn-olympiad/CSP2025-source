#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,z,cnt=1;
long long a[1010],b[20][20];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=m;j++)
		{
			cin>>a[cnt];
			cnt++;
		}
	}
	cnt--;
	z=a[1];
	for(long long i=1;i<=cnt;i++)
	{
		for(long long j=1;j<=cnt-1;j++)
		{
			if(a[j]<a[j+1])
			{
				swap(a[j],a[j+1]);
			}
		}
	}
	for(long long i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			long long sum=1;
			for(int j=(i-1)*n+1;j<=n+(i-1)*n;j++)
			{
				b[sum][i]=a[j];
				sum++;
			}
		}
		else
		{
			long long sum=1;
			for(int j=n+(i-1)*n;j>=(i-1)*n+1;j--)
			{
				b[sum][i]=a[j];
				sum++;
			}
		}
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=m;j++)
		{
			if(b[i][j]==z)
			{
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}
