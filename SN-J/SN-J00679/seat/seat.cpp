#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],b,c,d,e;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==b)
		{
			c=n*m+1-i;
		}
	}
	if(c>2*n)
	{
		
		d=c%(2*n);
		e=(c-d)/n;
	}
	else
	{
		d=c;
		e=0;
	}
	if(d<=n)
	{
		cout<<e+1<<" "<<d;
	} 
	if(d>n)
	{
		cout<<e+2<<" "<<2*n+1-d;
	}
	return 0;
}
