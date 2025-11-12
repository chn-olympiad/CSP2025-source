#include<bits/stdc++.h>
using namespace std;
int a[10000];
int n,m,wz,h,l;
bool c(int x,int y)
{
	return x>y;
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
	wz=a[1];
	sort(a+1,a+n*m+1,c);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==wz)
		{
			l=(i+n-1)/n;
			h=i%n;
		}
	}
	if(l%2==0)
	{
		h=n-h+1;
	}
	cout<<l<<" "<<h;
	return 0;
}
