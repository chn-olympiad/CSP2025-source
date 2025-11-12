#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],r;
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
	sort(a+1,a+1+n*m);
	for(int i=n*m,j=1,x,y;i>=1;i--,j++)
	{
		x=(j-1)/n+1;
		y=(j-1)%n+1;
		if(x%2==0)
		{
			y=m-y+1;
		}
		if(a[i]==r)
		{
			cout<<x<<" "<<y;
			return 0;
		}
	}
}
