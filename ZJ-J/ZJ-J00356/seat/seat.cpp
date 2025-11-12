#include<bits/stdc++.h>
using namespace std;
int x=1,y=1,s,a[110],n,m;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	s=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m*n;i++)
	{
		if(a[i]==s)
		{
			cout<<x<<" "<<y;
			
		}
		if(x%2==1)
		{
			y++;
			if(y>n)
			{
				y--;
				x++;
			}
		}
		else 
		{
			y--;
			if(y<1)
			{
				y++;
				x++;
			}			
		}
	}
	return 0;
}
