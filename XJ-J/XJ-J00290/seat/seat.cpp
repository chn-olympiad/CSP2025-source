#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,a[100],l;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	l=a[1];
	sort(a[1],a[99]);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]=l)
		{
			if(i/n%2==0)
			{
				if(i%n!=0)
				{
					cout<<i/n+1<<i%n;
				}
				else 
				{
					cout<<i/n<<1;
				}
			}
			if(i/n%2!=0)
			{
				if(i%n!=0)	
				{
					cout<<i/n+1<<n-i%n+1;
				}
				else 
				{
					cout<<i/n<<n;
				}
			}
		}
	}
	return 0;
}
