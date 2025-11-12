#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],t;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i = 2;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])
		{
			t++;
		}
	}
	int b = t/n+1;
	t = t+1;
	int c = t%n;
	if(c == 0)
	{
		c = n;
	}
	if(b%2 == 0)
	{
		c = n-c+1;
	}
	cout<<b<<' '<<c;
	return 0;
}