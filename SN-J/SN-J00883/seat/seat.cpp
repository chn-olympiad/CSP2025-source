#include<bits/stdc++.h>
using namespace std;
long long a[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m=0;
	long long r=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	long long l,h=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			if(i%n==0)
			{
				l=i/n;				
			}
			else
			{
				l=i/n+1;
			}
			if(l%2==0)
			{
				if(i%n==0)
				{
					h=1;
				}
				else
				{
					h=n+1-i%n;
				}
			}
			else
			{
				if(i%n==0)
				{
					h=n;
				}
				else
				{
					h=i%n;
				}
			}
			break;
		}
	}
	cout<<l<<' '<<h;
	return 0;
}
