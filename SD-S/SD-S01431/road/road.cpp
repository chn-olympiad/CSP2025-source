#include <bits/stdc++.h>
using namespace std;
int n,m,k,u[1000005],v[1000005],w[1000005],ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0)
	{
		for(int i=1; i<=m; i++) cin>>u[i];
		for(int i=1; i<=m; i++) cin>>v[i];
		for(int i=1; i<=m; i++) cin>>w[i];
		for(int i=1; i<=n-1; i++)
		{
			for(int j=i;j<m;j++)
			{
				if(w[j]>w[j+1])
				{
					int aa=w[j];
					w[j]=w[j+1];
					w[j+1]=aa;
				}
			}
		}
		for(int i=1;i<=n-1;i++)ans+=w[i];
	}
	cout<<ans<<endl;
	return 0;
}
