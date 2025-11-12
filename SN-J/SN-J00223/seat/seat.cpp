//ºº±õÇøºº±õ³õ¼¶ÖÐÑ§  ÌÆ³ÐÏ£
#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1][m+1] ;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	int num=a[1][1];
	for(int k=1;k<n*m;k++)
	{	
		for(int i=1;i<n;i++)
		{
			if(i%2==1)
			{
				for(int j=1;j<m;j++)
				{
					if(j=m)
					{
						if(a[i][j]<a[i+1][m])
						{
							swap(a[i][j],a[i+1][m]);
						}
					}
					else if(a[i][j]<a[i][j+1])
					{
						swap(a[i][j],a[i][j+1]);
					}
				}
			}
			else
			{
				for(int j=m;j>=1;j--)
				{
					if(j=1)
					{
						if(a[i][j]<a[i+1][1])
						{
							swap(a[i][j],a[i+1][1]);
						}
					}
					else if(a[i][j]<a[i][j-1])
					{
						swap(a[i][j],a[i][j-1]);
					}
				}
			}	
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(a[i][j]==num)
			{
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
} 
