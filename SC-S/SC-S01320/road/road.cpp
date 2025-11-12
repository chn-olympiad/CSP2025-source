#include<bits/stdc++.h>
using namespace std;
int b[105][1000005];
int c[1000005];
bool f[1000005];
struct stu{
	int c1,c2,cost; 
}s[1000005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>s[i].c1>>s[i].c2>>s[i].cost;
		c[i]=c[i-1]+s[i].cost;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>b[i][0];
		for(int j=1;j<=n;j++)
		{
			cin>>b[i][j];
		}
	}
	cout<<c[m];
	return 0;
}