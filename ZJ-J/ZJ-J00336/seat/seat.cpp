#include<bits/stdc++.h>
using namespace std;
int i,j,len,a[105],n,m,s,k,c,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	for(i=1;i<=s;i++)
	{
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+s+1);
	for(i=1;i<=s;i++)
	{
		if(a[i]==k)
			len=s+1-i;
	}
	c=(len-1)/n+1;
	cout<<c<<' ';
	if(c%2==1)
	{
		if(len%n==0)
		{
			r=n;
		}
		else
		{
			r=len%n;
		}
	}
	else
	{
		r=(n+1-(len%n))%n;
		if(r==0)
		{
			r=n;
		}
	}
	cout<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
