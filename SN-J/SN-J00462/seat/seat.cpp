#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1005],q,w,e,x,y;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	q=n*m;
	for(int i=1;i<=q;i++)
	{
		cin>>a[i];
	}
	w=a[1];
	sort(a+1,a+q+1,cmp);
	while(a[e]!=w)
	{
		e++;
	}
	w=e%n;
	if(w==0)
	{
		y=e/n;
		
	}
	else
	{
		y=e/n+1;
	}
	if(y%2==0)
	{
		if(w==0)
		{
			x=1;
		}
		else
		{
			x=n-w+1;
		}
		
	}
	else
	{
		if(w==0)
		{
			x=n;
		}
		else
		{
			x=w;
		}
	}
	cout<<y<<" "<<x;
	return 0;
}

