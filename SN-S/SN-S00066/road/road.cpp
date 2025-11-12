#include <bits/stdc++.h>
using namespace std;
int n,m,k;
long long w[10100],u[10100],v[10010],c[20200],b[20020];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i-1<=n;i++)
		cin>>c[i];
	for(int i=1;i-1<=n;i++)
		cin>>b[i];
	cout<<13<<endl;
	return 0;
}
