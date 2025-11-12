#include<bits/stdc++.h>
using namespace std;
long long a[1010][1010],n,m,k , sum;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(a,0x7f,sizeof(a));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y;
		a[x][y]=a[y][x]=w;
		sum+=w;
	}
	for(int i=1;i<=k;i++)
	{
		int a1,a2,a3,a4,a5;
		cin>>a1>>a2>>a3>>a4>>a5;
	}
	cout << sum ;
	return 0;
 } 
