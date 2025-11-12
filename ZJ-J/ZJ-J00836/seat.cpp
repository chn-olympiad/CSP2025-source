#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int a[100]={};
	int x=1;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n*m;i++)
	{
		if(a[i]>a[0])
		{
			x+=1;
		}
	}
	int xn,xm;
	xm=int((x-1)/n)+1;
	if(xm%2==0)
	{
		xn=n+1-x+(n*(xm-1));
	}
	else
	{
		xn=x-(xm-1)*n;
	}
	cout<<xm<<xn;
	return 0;
}