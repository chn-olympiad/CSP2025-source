#include<bits/stdc++.h>
using namespace std;
int a[100010];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,x,o,p;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		x=a[1];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==x)
		{
			if(i<=n)
			{
				cout<<1<<" "<<i;
				return 0;
			}
			else
			{
				o=(i+n-1)/n;
				if(o%2==1)
				{
					if(i%n==0)p=n;
					else p=i%n;
				}
				else
				{
					i=i%n;
					if(i==0)i=n;
					p=n-i+1;
				}
				cout<<o<<" "<<p;
				return 0;
			}
		}
	}
	return 0;
}