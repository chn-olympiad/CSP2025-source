#include<bits/stdc++.h>
//using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	std::cin>>n>>m;
	int f=n*m,t;
	int a[n][m],g[f];
	for (int i=1;i<=f;i++)
	{
		std::cin>>g[i];
		for(int j=1;j<=i;j++)
		{
		
			if(g[i]>g[j])
			{
				int c;
				c=g[j];
				g[j]=g[i];
				g[j]=c;
			}
//			if(g[i]>g[f-j])
//			{
//				int c;
//				c=g[f-j];
//				g[f-j]=g[i];
//				g[f-j]=c;
//			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i%2==0)
		{
			for(int j=m;j>=1;j--)
			{
				a[i][j]=g[t];
				t++;
			}
		}
		if(i%2!=0)
		{
			for(int j=1;j<=m;j++)
			{
				a[i][j]=g[t];
				t++;
			}
		}
		
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==99)
			{
				std::cout<<i<<" "<<j;
				break;
			}
		}
	}
}
