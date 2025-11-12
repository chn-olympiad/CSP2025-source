#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int t[110];
int n,m,idx=1,tt;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>t[i];
	tt=t[1];
	sort(t+1,t+1+n*m,cmp);
	for(int i=1;i<=n; )
	{
		for(int j=1;j<=m;j++)
			a[i][j]=t[idx++];
		i++;
		if(i>n)
			break;
		for(int j=m;j>=1;j--)
			a[i][j]=t[idx++];
		i++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==tt)
			{
				cout<<i<<' '<<j;
				break;
			}
		}
	}
	return 0;
}
