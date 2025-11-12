#include<bits/stdc++.h>
using namespace std; 
int n,m,ans,cnt;
long long a[100],b[100][100];
bool cmp(int x,int y)
{
	if(x>=y) return true;
	else return false; 
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<=n*m;i++)
	{
		cin>>a[i];
	}
	ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=cnt;k++)
			{
				b[j][i]=a[k];
			}
		}
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(b[i][j]==ans)
			{
				cout<<i<<j;
			}
		}
	}
	return 0;
}
