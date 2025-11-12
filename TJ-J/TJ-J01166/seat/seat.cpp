#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[105],r,s;
	int n,m;
	cin>>n>>m;
	int p=n*m;
	for(int i=1;i<=p;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+p+1);
	for(int i=1;i<=p;i++)
	{
		if(a[i]==r)
		{
			s=p-i+1;
		}
	}
	if(s%n==0)
	{
		m=s/n;
		if(m%2==0)
		{
			n=1;
		}
	}
	else
	{
		m=s/n+1;
		if(m%2==0)
		{
			n=n-(s%n)+1;
		}
		else
		{
			n=s%n;
		}
	}
	cout<<m<<" "<<n;
	return 0;
}
