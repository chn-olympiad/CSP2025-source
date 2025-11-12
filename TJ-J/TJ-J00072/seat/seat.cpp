#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+2];
	cin>>a[1];
	int x=a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==x)
		{
			int l=(i-1)/n+1;
			int h=0;
			if(l%2==1)
			{
				h=i%n;
				if(h==0)
				{
					h=m;
				}
			}
			else
			{
				h=m-i%n+1;
				if(h>m)
				{
					h=0;
				}
			}
			cout<<l<<" "<<h;
			break;
		}
		
	}
	return 0;
}
