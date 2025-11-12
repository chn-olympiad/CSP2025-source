#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],b[105],ans[15][15];
bool cmp(int c,int d)
{
	return c>d;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n*m+1,cmp);
	int k=0;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++) ans[j][i]=b[++k];
		}
		else
		{
			for(int j=n;j>=1;j--) ans[j][i]=b[++k];
		}
	}
	int x,y;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(ans[i][j]==a[1]) x=i,y=j;
		}
	}
	cout<<y<<" "<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
