#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101],b=0;
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)cin>>a[i];
	if (n==1&&m==1)
	{
		cout<<1<<" "<<1;
	}
	else
	{
		if (n==1)
		{
			for (int i=1;i<=n*m;i++)
			{
				if (a[i]>a[1])
				{
					b++;
				}
			}
			cout<<1<<" "<<b+1;
		}
		else
		{
			for (int i=1;i<=n*m;i++)
			{
				if (a[i]>a[1])
				{
					b++;
				}
			}
			cout<<b+1<<" "<<1;
		}
	}
	return 0;
}
