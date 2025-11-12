#include<bits/stdc++.h>
using namespace std;
int n,m,a[108],r,x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int t=n*m;
	for(int i=1;i<=t;i++)cin>>a[i];
	r=a[1];
	sort(a+1,a+t+1);
	for(int i=1;i<=t;i++)
	{
		if(a[i]==r)
		{
			y=(t-i+n)/n;//第y列 
			if(y%2==1)//奇数列
			{
				x=(t-i+1)%n;
				if(x==0)x=n;
			} 
			else
			{
				x=n-(t-i+1)%n+1;
			}
			break;
		}	 
	}
	cout<<y<<" "<<x;
	return 0;	
} 
