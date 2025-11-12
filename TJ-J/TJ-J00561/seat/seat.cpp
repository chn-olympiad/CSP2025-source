#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[1005],pop;
	int n1,m1;
	cin>>n>>m;
	cin>>a[1];
	int x=a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]<a[i+1])
		{
			int t=a[i];
			a[i]=a[i+1];
			a[i+1]=t;
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==x)
		{
			pop=i;
		}
	}
	if(pop<=n)
	{
		n1=pop;
		m1=1;
	}
	else
	{
		if((pop/n+1)%2==1)
		{
			n1=pop%n;
			m1=pop/n+1;
		}
		else
		{
			n1=n-pop%n+1;
			m1=pop/n+1;
		}
	}
	cout<<m1<<" "<<n1;
	
}
