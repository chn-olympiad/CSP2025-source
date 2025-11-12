#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],c,r,i,ch,w;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	ch=a[1];
	sort(a+1,a+n*m+1);
	for(i=1;i<=n*m;i++)
	{
		if(a[i]==ch)
		{
			w=n*m-i+1;
			break;
		}
	}
	c=w/n;
	if(w%n>0)
	{
		c++;
	}
	if(c%2==1)
	{
		if(w>n)	r=w%n;
		else r=w;
	}
	else
	{
		if(w>n)	r=n-w%n+1;
		else r=n-w+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
