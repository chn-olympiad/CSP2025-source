#include <bits/stdc++.h>
using namespace std;
int n,m,pm = 1,a;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;

	for(int i=2;i<=n*m;i++)
	{
		int ls;
		cin>>ls;
		if(ls>a)
		{
			pm++;
		}
		
	}
	int c = floor((pm*1.0)/n+0.99);
	int r;
	if(c%2==0)
	{
		r = pm%n;
		if(r==0)
		{
			r = n;
		}
		r = n-r+1;
	}
	else
	{
		r = pm%n;
		if(r==0)
		{
			r = n;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
