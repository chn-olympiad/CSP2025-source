#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,a[105],b=0,c,d,e;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==b)
		{
			c=i;
		}
	}
	d=(c-1)/n+1;
	e=c%(2*n);
	if(e==0)
	{
		e=1;
	}
	if(e>n)
	{
		e=e-n;
		if(e==1)
		{
			e=n;
		}
		else if(e==2)
		{
			e=n-1;
		}
		else if(e==3)
		{
			e=n-2;
		}
		else if(e==4)
		{
			e=n-3;
		}
		else if(e==5)
		{
			e=n-4;
		}
		else if(e==6)
		{
			e=n-5;
		}
		else if(e==7)
		{
			e=n-6;
		}
		else if(n==8)
		{
			e=n-7;
		}
		else if(n==9)
		{
			e=n-8;
		}
	}
	cout<<d<<" "<<e<<endl;
	return 0;
}
