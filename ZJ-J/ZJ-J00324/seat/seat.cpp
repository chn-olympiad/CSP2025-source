#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],p,ii;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		p=a[1];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==p)
		{
			ii=i;
			break;
		}
		else continue;
	}
	if(n==1)
	{
		cout<<ii<<" "<<1;
		return 0;
	}
	if(m==1)
	{
		cout<<1<<" "<<ii;
		return 0;
	}
	else if(n==2)
	{
		int l;
		if(ii%2==1)
		{
			l=(ii+1)/2;
		}
		else
		{
			l=ii/2;
		}
		if(l%2==0)
		{
			if(ii%2==1)
			{
				cout<<l<<" "<<2;
			}
			else cout<<l<<" "<<1;
		}
		else
		{
			if(ii%2==1)
			{
				cout<<l<<" "<<1;
			}
			else cout<<l<<" "<<2;
		}
	}
	else if(m==2)
	{
		if(ii<=n*m/2)
		{
			cout<<1<<" "<<ii;
		}
		else cout<<2<<" "<<n*m+1-ii;
	}
	else
	{
		int l,h;
		if(ii%4==0)
		{
			l=ii/4;
		}
		else l=(ii+n-ii%n)/n;
		if(l%2==0)
		{
			h=ii%4;
		}
		else if(l%2==1&&ii%4==0)
		{
			h=1;
		}
		else
		{
			h=n+1-ii%4;
		}
		cout<<l<<" "<<h;
	}
	return 0;
}
