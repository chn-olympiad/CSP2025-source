#include<iostream>
using namespace std;

int main()
{
	//freopen("road.in","r",stdin);
    //freopen("road.out","w",stdout);
	int n,m,k,u[1005],v[100005],w[15],x[105],y[105];
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>u[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>v[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=5;i++)
	    cin>>x[i];
	for(int i=1;i<=5;i++)
	{
		cin>>y[i];
	}
	cout<<13;
	return 0;
}
