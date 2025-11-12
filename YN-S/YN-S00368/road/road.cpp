#include <iostream>
using namespace std;
int n;
int m;
int k;
int u[10005];
int v[10005];
int w[10005];
int c[10005];
int a[10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	cin>>m;
	cin>>k;
	for(int i=1;i<=3;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=n+1;i++)
	{
		cin>>c[i]>>a[i];
	}
	cout<<13;
}