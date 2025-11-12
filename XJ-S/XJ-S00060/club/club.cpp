#include<bits/stdc++.h>
using namespace std;
int  t, a[10100][10100], mx=-1, ans=0;
int j,n[10];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;

	for(int i=0;i<t;i++)
	{
		ans=0;
		cin >> n[i];
		for(j=0;j<n[i];j++)
		{
		cin >> a[0][j] >> a[1][j] >> a[2][j];
		if(a[2][j]>=10)
		{
			a[2][j]=0;
		}
		if(a[1][j]>=10)
		{
			a[1][j]=0;
		}
		if(a[0][j]>=10)
		{
			a[0][j]=0;
		}
		if(a[0][j]==1)
		{
			a[0][j]=0;
		}
		if(a[1][j]==1)
		{
			a[1][j]=0;
		}
		if(a[2][j]==1)
		{
			a[2][j]=0;
		}
		if(a[0][j] > a[1][j] && a[0][j] > a[2][j])
		{
			ans+=a[0][j];
		}
		else if(a[1][j] > a[0][j] && a[1][j] > a[2][j])
		{
			ans+=a[1][j];
		}
		else if(a[2][j] > a[0][j] && a[2][j] > a[1][j])
		{
			ans+=a[2][j];
		}
		}
		cout << ans;
	}
	return 0;
} 
