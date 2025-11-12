#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,a[120];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int peo=n*m;
	for(int i=1;i<=peo;i++)
	{
		cin>>a[i];
	}
	int last=a[1];
	sort(a+1,a+peo+1,cmp);
	int a_now;
	for(int i=1;i<=peo;i++)
	{
		if(a[i]==last)
		{
			a_now=i;
			break;
		}
	}
	if(a_now%n==0)
	{
		cout<<a_now/n<<" ";
	}
	else
	{
		cout<<a_now/n+1<<" ";
	}
	int a_now_best=a_now;
	if(a_now%n!=0)
	{
		a_now_best=(a_now/n+1)*n;
	}
	if(a_now_best/n%2==0)//up
	{
		cout<<n-a_now%n+1;
	}
	else
	{
		if(a_now%n==0)
		{
			cout<<n;
		}
		else
		{
			cout<<a_now%n;
		}
	}
	return 0;
}
