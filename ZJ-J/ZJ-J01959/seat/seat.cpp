#include<bits/stdc++.h>
using namespace std;
int a[10005],n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int r;
	cin>>n>>m>>r;
	a[1]=r;
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			r=m*n-i+1;
			break;
		}
	}
	
	int c=(r-1)/n+1;
	int h=(r-1)%n+1;
	if(c%2==0)
	{
		h=n-h+1;
	}
	cout<<c<<' '<<h;
	return 0;
}
