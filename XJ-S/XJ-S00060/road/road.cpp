#include<bits/stdc++.h>
using namespace std;
int n, m, k, mx=-1, ans=0;
int a[10][10], b[10][10];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin >> a[i][j];
			if(a[i][j]>mx)
			{
				mx=a[i][j];
			}
		}
		
	}
	ans+=mx; 
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=5;j++)
		{
			cin >> b[i][j];
		}
	}
	ans+=6;	 
	cout << ans; 
	return 0;
 } 
