#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r,R,cnt;
	cin>>n>>m;
	int a[n][m];
	int b[105];
	for(int i=1;i<=n*m;i++)
	{
		cin>>b[i];
	}
	R=b[1];
	for(int i=1;i<=n*m-1;i++)
	{
		for(int j=1;j<=n*m-1;j++)
		{
			if(a[j]<a[j+1])
			{
				swap(b[j],b[j+1]);
			}
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(b[i]==R)
		{
			cnt=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(cnt<=n)
		{
			c=1;
			r=cnt;
		}
		else
		{
			c=i+m%cnt;
			r=cnt-n;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
