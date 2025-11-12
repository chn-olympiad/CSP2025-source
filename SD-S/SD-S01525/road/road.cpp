#include<iostream>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans=0;
	cin>>n>>m>>k;
	int a,b,c;
	for(int i=1;i<=m;i++)
	{
		
		cin>>a>>b>>c;
	}
	for(int j=1;j<=k;j++)
	{
		for(int i=1;i<=n+1;i++)
		{
			cin>>a;
			ans+=a;
		}
	}
	cout<<a;
	return 0;
}
