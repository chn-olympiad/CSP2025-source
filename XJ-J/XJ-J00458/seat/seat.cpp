#include <bits/stdc++.h>
using namespace std;
int d[2]={-1,1};
int n,m,a,ar,seat[20][20];
priority_queue<int> p; 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin>>a;
		if (i==1)
		{
			ar=a;
		}
		p.push(a);
	}
	for (int i=1;i<=m;i++)
	{
		if (i%2==1)
		{
			a=1;
		}
		else
		{
			a=n;
		}
		for (int j=a;j>=1&&j<=n;j+=d[i%2])
		{
			if (p.top()==ar)
			{
				cout<<i<<" "<<j;
				return 0;
			}
			else
			{
				p.pop();
			}
		}
	}
	return 0;
 } 
