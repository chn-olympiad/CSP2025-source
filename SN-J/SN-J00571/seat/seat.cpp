#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],cnt[20][20];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	} 
	int ans=a[1];
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(j%2==1)
			{
				int num=i-n*(j-1);
				cnt[num][j]=a[i];
			}
			else
			{
				if(i<=n)
				{
					int num=i;
					cnt[num][j]=a[i];
				}
				else
				{
					int num=n*j-i+1;
					cnt[num][j]=a[i];
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(cnt[i][j]==ans)
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
