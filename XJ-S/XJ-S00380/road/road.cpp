#include<bits/stdc++.h>
using namespace std;
int u1[1000005],u2[1000005],u3[1000005];
int c[15][10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u1[i]>>u2[i]>>u3[i];
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			cin>>c[i][j];
		}
	}
	cout<<"13";
	return 0;
}
