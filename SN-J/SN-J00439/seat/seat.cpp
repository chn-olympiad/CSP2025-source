#include<bits/stdc++.h>
using namespace std;
int n,m,x,k,r,c;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
	{
		cin >> a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1);
	int u=1;
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==x)
		{
			k=u;
			break;
		}
		u++;
	}
	if(k%n==0)
	{
		c=k/n;
			if(c%2==1)
			{
				r=n;
			}
			else
			{
				r=1;
			}
	}
	else
	{
		c=k/n+1;
		if(c%2==1)
		{
			r=k%n;
		}
		else
		{
			r=(n+1)-(k%n);
		}
	}
	cout << c << ' ' << r;
	return 0;
}
