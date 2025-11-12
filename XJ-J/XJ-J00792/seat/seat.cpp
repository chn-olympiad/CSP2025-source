#include <bits/stdc++.h>
using namespace std;
long long n, m, a[101], b[101][101], r, cnt=0, j=1, len, t, x=1, y=1;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin>>n>>m;
	len=n*m;
	for(long long i=1;i<=len;i++)
	{
		cin>>a[i];
		if(j>=m) j=0;
		b[i][j]=a[i]; 
		j++;
	}
	r=a[1];
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=m;j++)
		{
			if(i%2==1)
			{
				sort(b[i]+1, b[i]+n+1);
			}
			else
			{
				sort(b[i]+1, b[i]+n+1, greater<long long>());
			}
		}
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=m;j++)
		{
			if(b[i][j]==r)
			{
				x=i;
				y=j;
				break;
			}
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
