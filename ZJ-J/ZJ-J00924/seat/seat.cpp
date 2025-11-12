#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[201];
pair<int,int> b[11][11];
bool cmp(pair<int,int> a,pair<int,int> b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].first;
	}
	a[1].second=1;
	sort(a+1,a+n*m+1,cmp);
	int t=1;
	for(int j=1;j<=m;j++)
	{
		if(j%2==1)
		{
			for(int i=1;i<=n;i++)b[i][j]=a[t],t++;
		}
		else
		{
			for(int i=n;i>=1;i--)b[i][j]=a[t],t++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)if(b[i][j].second==1)
		{
			cout<<j<<" "<<i;
			return 0;
		}
	}
	return 0;
}
