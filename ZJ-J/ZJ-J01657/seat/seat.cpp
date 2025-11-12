#include<bits/stdc++.h>
using namespace std;

const int N=1e2+10;

int a[N];
int n,m;
int p,c;
int h,l;
int x,y;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	
	c=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==c)
		{
			p=n*m-i+1;
			break;
		}
	}
//	cout<<p<<'\n';
	
	l=(p+n-1)/n;
	h=(p+n-1)%n;
	x=l;
	if(l%2==0)
	{
		y=n-h;
	}
	else y=h+1;
	
	cout<<x<<' '<<y;
	                             
	return 0;
}
//fc seat.out seat2.ans