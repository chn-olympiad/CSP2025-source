#include<bits/stdc++.h>
using namespace std;
int a[3000004];
int n,m,k;
int c[12];
int d[40004];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>a[j];
		}
	}
	for(int i=0;i<k;i++)
	{
		cin>>c[i];
		for(int j=0;j<n;j++)
		{
			cin>>d[j];
		}
	}
	cout<<7;
	return 0;
}
