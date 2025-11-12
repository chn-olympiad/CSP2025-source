#include<bits/stdc++.h>
using namespace std;
int a[105],m,n,tgt,tmp=1;
int mp[15][15];
bool cmp(int c,int d) 
{
	return c>d;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	int s=n*m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1) tgt=a[i];
	}
	sort(a+1,a+s+1,cmp);
	for(int i=1,j=1;i<=n and j<=m;i++)
	{
		if(j%2==0) mp[n-i+1][j]=a[tmp];
		else mp[i][j]=a[tmp];
		tmp++;
		if(i==n) j++,i=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]==tgt) cout<<j<<' '<<i;
		}
	}
	return 0;
}
