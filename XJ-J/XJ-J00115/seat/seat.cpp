#include<bits/stdc++.h>
using namespace std;
long long int a[15][15],b[105],n,m,s,x,y,t=0,k=0;
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>b[i];
		if(i==1)
		s=b[i];
		k++;
	}
	sort(b+1,b+1+n*m);
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				a[i][j]=b[k--];
				if(a[i][j]==s)
				{
					x=i;
					y=j;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				a[i][j]=b[k--];
				if(a[i][j]==s)
				{
					x=i;
					y=j;
				}
			}
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
