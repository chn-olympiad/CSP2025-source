#include <bits/stdc++.h>
using namespace std;
int n,m,a[10005][10005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x=0,z=0;
	int maxn;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			maxn=max(maxn,a[i][j]);
			
		}
	}
	x=rand();
	z=rand();
	cout<<x<<" "<<z;
	
	return 0;
}
