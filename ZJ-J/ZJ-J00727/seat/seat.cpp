#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1010];
long long v[1010][1010];
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	long long q=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(long long i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(long long j=1;j<=m;j++)
				if(a[(i-1)*m+j]==q)
				{
					cout<<i<<" "<<j;
					break;
				}
		}
		if(i%2==0)
		{
			for(long long j=m;j>=1;j--)
				if(a[i*m-j+1]==q)
				{
					cout<<i<<" "<<j;
					break;
				}
		}
	}
	return 0;
}