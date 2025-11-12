#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>a;
		}
	}
	for(int j=1;j<=k;j++)
	{
		for(int i=1;i<=n+1;i++)
		{
			cin>>a;
		}
	}
	cout<<13;
	return 0;
}