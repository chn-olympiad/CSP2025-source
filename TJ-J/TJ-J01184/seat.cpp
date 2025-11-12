#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x[1000],R,top,c,r,b,a;
	cin >> n >> m;
	for (int i=1;i<=n*m;i++)
	{
		cin >> x[i];
	}
	R=x[1];
	sort(x+1,x+n*m+1);
	for (int i=1;i<=n*m;i++)
	{
		if(x[i]==R)
		{
			a=i;
		}
		b+=1;
	}
	top=b-a+1;
	if (top%n==0)
	{
		if(top/n%2==1)
		{
			n=n;
			m=top/n;
		}
		else
		{
			n=1;
			m=top/n;
		}
	}
	else
	{
		if ((top/n+1)%2==1)
		{
			r=top%n;
			c=top/n+1;
		}
		else
		{
			r=n-(top%n-1);
			c=top/n+1;
		}
	}
	cout << c << " " << r;
}
