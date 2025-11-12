#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	int cnt=0;
	for(int i=1;i<=n*m;i++)
	{
		cnt++;
		if(a[i]==x)
		{
			break;
		}
	}
	if(cnt%n==0)
	{
		int y=cnt/n;
		if(y%2==0)
		{
			cout<<y<<" "<<1;
		}
		else
		{
			cout<<y<<" "<<n;
		}
	}
	else
	{
		int z=cnt/n+1;
		if(z%2==0)
		{
			cout<<z<<" "<<1+cnt%n;
		}
		else
		{
			cout<<z<<" "<<cnt%n;
		}
	}
	return 0;
} 
