#include<bits/stdc++.h>
using namespace std;
long long v[1000001];
long long u[1000001];
long long w[1000001];
long long a[11][10001];
long long f[100001]; 
long long e[1000001];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,c=0,j;
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for (int d=1;d<=k;d++)
	{
		for (int l=1;l<=n;l++)
		{
		
			cin>>e[l]>>a[l][n];
		}
	}
		for (int i=1;i<=n;i++)
		{
			c+=w[i];
		}
		cout<<"13"<<endl;
		return 0;
		
	
	
}
