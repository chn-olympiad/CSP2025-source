#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],r,x,y;
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
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			x=(i+n-1)/n;
			if(x%2)
			{
				y=i%n;
				if(y==0)
				{
					y=n;
				}
			}
			else
			{
				y=n+1-i%n;
				if(i%n==0)
				{
					y=1;
				}
			}
			break;
		}
	}
	cout<<x<<" "<<y;
	return 0;
 } 
