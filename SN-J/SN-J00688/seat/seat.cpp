#include<bits/stdc++.h>
using namespace std;
int n,m,r,num,h,l;
int a[110],b[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++)
	{
		cin>>b[i];
	}
	r=b[1];
	sort(b,b+n*m+1);
	for(int i=1; i<=n*m; i++)
	{
		a[i] = b[n*m+1-i];
	}
	for(int i=1; i<=n*m; i++)
	{
		if(r == a[i])
		{
			num = i;
		}
	}
	if(m == 2)
	{
		if(num<=n)
		{
			cout<<1<<" "<<num;
			return 0;
		}
		if(num>n)
		{
			if(num%n==1)
			{
				cout<<2<<" "<<n;
			}
			else
			{
				cout<<2<<" "<<n-num%n;
				return 0;
			}	
		}
	}
	if(num%n == 0)
	{
		l = num/n;
		if(l%2==0)
		{
			h = n;
		}
		else
		{
			h = 1;
		}
		cout<<l<<" "<<h;
		return 0;
	}
	else
	{
		l = num/n+1;
	}
	if(l%2==0)
	{
		h = n-num%n;
	}
	else
	{
		h = num%n;
	}
	cout<<l<<" "<<h;
	return 0;
}
