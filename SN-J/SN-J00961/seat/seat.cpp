#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000],k=1,s;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	s=a[1];
	while(k==1)
	{
		k=0;
		for(int i=2;i<=n*m;i++)
		{
			if(a[i]>a[i-1])
			{
				swap(a[i],a[i-1]);
				k=1;
			}
		}
		
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==s)
		{
			s=i;
		}
	}
	if(s%n==0)
	{
		cout<<s/n<<" ";
		if((s/n)%2==0)
		{
			cout<<1;
		}
		else
		{
			cout<<n;
		}
	}
	else if(s%n!=0)
	{
		cout<<s/n+1<<" ";
		if((s/n+1)%2==0)
		{
			cout<<n+1-(s%n);
		}
		else
		{
			cout<<s%n;
		}
	}
	return 0;
}
