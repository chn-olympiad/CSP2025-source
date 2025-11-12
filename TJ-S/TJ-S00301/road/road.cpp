#include <bits/stdc++.h>
using namespace std;
const long long N=1e6+5,M=1e4+5;
int n,m,k;
long long u[N],v[N],w[N],c[N],a[15][M],ans1,ans2,ans3,ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) 
	{
		cin>>u[i]>>v[i]>>w[i];
		ans1+=w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		ans2+=c[i];
		for(int j=1;j<=n;j++) 
		{
			cin>>a[i][j];
			ans3+=a[i][j];
		}
	}
	if(k) ans=ans1+ans2+ans3;
	else ans=ans1;
	cout<<ans;
	return 0;
}
