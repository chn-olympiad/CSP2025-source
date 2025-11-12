#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int w[100010],u[100010],v[100010];
int ans=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		ans+=w[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

