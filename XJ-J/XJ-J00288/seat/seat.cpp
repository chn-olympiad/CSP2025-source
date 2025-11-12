#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[100010],r=-1,p,x,y;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(r<a[i])
		{
			r=a[i];
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			p=i;
		} 
	} 
	if(p%(2*n)<=4&&p%(2*n)!=0)
	{
		y=p%(2*n);
	}
	else
	{
		if(p%(2*n)>=5||p%(2*n)==0)
		{
			y=(2*n)-p%(2*n);
		} 
	}
	x=(p-1)/n+1;
	cout<<x<<" "<<y;
	return 0;
}
