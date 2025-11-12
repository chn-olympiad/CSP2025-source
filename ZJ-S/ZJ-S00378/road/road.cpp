#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u,v,w,ans=0;
	cin>>n>>m>>k;
	for(int i = 1;i<=n;i++)
	{
		cin>>u>>v>>w;
		if(u%2+v%2==1)
		{
			ans+=w;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
