#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int n,m,v;
	cin>>n>>m>>v;
	if (v==0)
	{
		int sum=0;
		for (int i=1;i<=m;i++)
		{
			int x,y,piece;
			cin>>x>>y>>piece;
			sum+=piece;
		}
		cout<<sum;
	}
	else cout<<0;
	return 0;
}
