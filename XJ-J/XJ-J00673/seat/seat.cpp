#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,c,r,f,ans,k;
int a[15][15],b[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	f=n*m;
	for(i=1;i<=f;i++)
	 cin>>b[i];
	
	ans=b[1];
	sort(b+1,b+1+f,greater<int>());
	k=0;
	for(j=1;j<=m;j++)
	{
		if(j%2==1)
		{
			for(i=1;i<=n;i++)
			 a[i][j]=b[++k];
		}
		else
		{
			for(i=n;i>=1;i--)
			 a[i][j]=b[++k];
		}
	}
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	if(a[i][j]==ans)
	cout<<j<<" "<<i;
	return 0;
}
