#include<bits/stdc++.h>
using namespace std;
int m,n,a[101],op,z=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	op=a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
		if(op<a[i])
		{
			z++;
		}
	}
	int x=z%n;
	int y=z/n;
	if(x==0)
	{
		if(y%2==0)
		{
			cout<<y<<" "<<1;
		}
		else
		{
			cout<<y<<" "<<n;
		}
	}
	else
	{
		y+=1;
		if(y%2==0)
		{
			cout<<y<<" "<<n-x+1;
		}
		else
		{
			cout<<y<<" "<<x;
		}
	}
	return 0;
}
