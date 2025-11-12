#include<bits/stdc++.h>
using namespace std;
int n,m,a[15][15],x,y,q,w[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int z=n*m;
	for(int i=1;i<=z;i++)
	{
		cin>>w[i];
	}
	q=w[1];
	sort(w+1,w+z+1);
	for(int i=1,s=z;i<=n;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=m;j++)
			{

				a[i][j]=w[s];
				if(w[s]==q)
				{
					x=i;y=j;
				}
				s--;
			}
		}
		else {
			for(int j=m;j>=1;j--)
			{

				a[i][j]=w[s];
				if(w[s]==q)
				{
					x=i;y=j;
				}
				s--;	
			}
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
