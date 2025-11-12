#include <iostream>
using namespace std;
long long n,m,i,j,k,a[1005],t;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	k=a[1];
	for(i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n*m;i++)
	{
		for(j=i+1;j<=n*m;j++)
		{
			if(a[j]>a[i])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			} 
		}
	}
	for(i=1;i<=n*m;i++)
	{
		if(a[i]==k)
		{
			if(i%n==0)
			{
				cout<<i/n<<' ';
				if((i/n)%2==0)
				{
					cout<<1;
				}
				else
				{
					cout<<n;
				}
			}
			else
			{
				cout<<i/n+1<<' ';
				if(((i/n)+1)%2==0)
				{
					cout<<n-(i%n)+1;
				}
				else
				{
					cout<<i%n;
				}
			}
			break;
		}
	}
	return 0;
}
