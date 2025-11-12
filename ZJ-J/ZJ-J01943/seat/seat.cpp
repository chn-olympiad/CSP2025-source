#include<bits/stdc++.h>
using namespace std;
int a[101],n,m,s[101],x,mi,c,y,op=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	x=a[1];
	sort(a+1,a+(n*m)+1,greater<int>());
	for(int i=1;i<=(n*m);i++)
	{
		if(a[i]==x)
		{
			c=i;
			break;
		}
	}
	x=1,y=1;
	for(int i=2;i<=c;i++)
	{
		if((i-1)%n==0) y++,op*=-1;
		else x+=op;
	}
	cout<<y<<' '<<x;
	return 0;
}