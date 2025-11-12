#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int b[1000005]; 
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>b[i];
	}
	return 0;
}
