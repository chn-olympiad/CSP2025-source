#include<bits/stdc++.h>
using namespace std;
int T,n,ans;
int a[3][10005];
int b[3][10005];
int c[3][10005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			cin >> a[1][i] >> b[1][i] >> c[1][i];
			a[2][i]=i;
			b[2][i]=i;
			c[2][i]=i;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n-i;j++)
			{
				if(a[1][j]<a[1][j+1])
				{
					swap(a[1][j],a[1][j+1]);
					swap(a[2][j],a[2][j+1]);
				}
				if(b[1][j]<b[1][j+1])
				{
					swap(b[1][j],b[1][j+1]);
					swap(b[2][j],b[2][j+1]);
				}
				if(c[1][j]<c[1][j+1])
				{
					swap(c[1][j],c[1][j+1]);
					swap(c[2][j],c[2][j+1]);
				}
			}
		}
		int k=0;
		for(int i=1;k<n/2&&i<=n;i++)
		{
			int x=0,y=0;
			for(int j=1;j<=n;j++)
			{
				if(b[2][j]==a[2][i])
				{
					x=j;
					break;
				}
			}
			for(int j=1;j<=n;j++)
			{
				if(c[2][j]==a[2][i])
				{
					y=j;
					break;
				}
			}
			if(a[1][i]>=b[1][x]&&a[1][i]>=c[1][y])
			{
					ans+=a[1][i];
					b[2][x]=-1;
					c[2][y]=-1;
					k++;
			}
		}
		k=0;
		for(int i=1;k<n/2&&i<=n;i++)
		{
			if(b[2][i]==-1)
			{
				continue;
			}
			int x=0;
			for(int j=1;j<=n;j++)
			{
				if(c[2][j]==b[2][i])
				{
					x=j;
					break;
				}
			}
			if(b[1][i]>=c[1][x])
			{
					ans+=b[1][i];
					c[2][x]=-1;
					k++;
			}
		}	
		k=0;
		for(int i=1;k<n/2&&i<=n;i++)
		{
			if(c[2][i]==-1)
			{
				continue;
			}
			ans+=c[1][i];
			c[2][i]=-1;
			k++;
		}
		cout << ans << endl;
		ans=0;
	}
	return 0;
}
