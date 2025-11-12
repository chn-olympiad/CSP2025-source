#include<bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int a[1000005];
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,c=0,r=0;
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
			
	}
	int o=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==o)
		{
			if(i%n==0)
				c=i/n;
			else
				c=i/n+1;
			if(i%n==0)//在头和尾
				if(c%2==0)
					r=1;
				else
					r=n;
			else if(i%n==1)
			{
				if(c%2==1)
					r=1;
				else
					r=n;
			}
			else//在中间
				if(c%2==1)
					r=i%n;
				else
					r=n-i%n;
			cout<<c<<" "<<r;
			return 0;
		}
	}
	return 0;
}
