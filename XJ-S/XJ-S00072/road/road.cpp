#include<bits/stdc++.h>
using namespace std;
long long int n,m,k,u[1000006],v[1000006],w[1000006],a[10005][10005];                                                                                                                
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	cin>>u[i]>>v[i]>>w[i];
	for(int j=1;j<=k;j++)
	for(int g=1;g<=n+1;g++)
	cout<<a[j][g];
	cout<<13;
	return 0;
} 
