#include <bits/stdc++.h>
using namespace std;
bool cmp(int p,int q)
{
	return q<p;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,b,c,r,a[105];
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
	{
		cin >> a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==x)
		{
			b=i;
			break;
		}
	}
	if(b%n==0)
	{
		c=b/n;
	}
	else
	{
		c=b/n+1;
	}
	if(c%2==0)
	{
		r=c*n-b+1;
	}
	else
	{
		r=b-c*n+n;
	}
	cout << c << " " << r;
	return 0;
}
