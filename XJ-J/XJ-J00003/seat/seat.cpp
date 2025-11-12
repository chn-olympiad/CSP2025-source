#include<bits/stdc++.h>
using namespace std;
int a[105]={0};
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];	
	}
	int r=a[1],l;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			l=i;
			break;
		}
	}
	int x=l/n,y=l%n;
	if(y==0)
	{
		if(x%2==0)
		{
			cout<<x<<" "<<1;
		}
		else
		{
			cout<<x<<" "<<n;
		}
	}
	else
	{
		x++;
		if(x%2==0)
		{
			cout<<x<<" "<<n+1-y;
		}
		else
		{
			cout<<x<<" "<<y;
		}
	}
}
