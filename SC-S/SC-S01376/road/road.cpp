#include<bits/stdc++.h>
using namespace std;
#define refi freopen("road.in","r",stdin);
#define outfi freopen("road.out","w",stdout);
int n,m,k;
int w[1000050]={0},u,v;
int c[10][10050]={0};
int main()
{
	refi
	outfi
	cin>>n>>m>>k;
	long long ans=0;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v>>w[i];
		ans+=w[i];
	}
	for(int i=0;i<k;i++)
		for(int j=0;j<=n;j++)
			cin>>c[i][j];
	cout<<ans<<endl;
	return 0;
} 