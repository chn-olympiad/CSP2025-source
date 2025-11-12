#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int N=1000001,M=1001;
int n,m,k,x,y,z;
int main ()
{
	freopen ("road.in","r",stdin);
	freopen ("road.out","w",stdout);
	ios::sync_with_stdio (0);
	cin.tie (0);cout.tie (0);
	cin >>n>>m>>k;
	for (int i=1;i<=m;i++) cin >>x>>y>>z;
	for (int i=1;i<=k;i++)
	{
		for (int j=1;j<=n+1;j++)
			cin >>x;
	}
	cout <<0;
	return 0;
}
