#include<bits/stdc++.h>
using namespace std;
int n,m,x,sum,ans=1;
int main()
{
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>x;
			if(i==1&&j==1)sum=x;
			else if(x>sum)ans++;
		}
	for(int i=1;i<=m;i++)
	{
		if(i%2)
		{
			for(int j=1;j<=n;j++)
			{
				if(--ans==0)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				if(--ans==0)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}

