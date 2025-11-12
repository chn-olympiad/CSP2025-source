#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105][105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int j = 1;j <= m;j++)
	{
		if(j%2==1)
		{
			for(int i = 1;i <= n;i++)
			{
				cin>>a[i][j];
			}
		} 
		else
		{
			for(int i = n;i >= 1;i--)
			{
				cin>>a[i][j];
			}
		}
	}
	int maxx=0;
	int x=1,y=1;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			int num=max(maxx,a[i][j]);
			if(num>maxx)
			{
				maxx=num;
				x=i,y=j;
			}
		}
	}
	cout<<y<<" "<<x; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
