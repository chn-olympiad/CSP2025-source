#include<iostream>
using namespace std;
int n,m,k,u[1000005],v[1000005],w[1000005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	return 0;
}
