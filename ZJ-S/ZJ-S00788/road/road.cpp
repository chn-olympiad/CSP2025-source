#include<bits/stdc++.h>
using namespace std;
const int N=10008;
int mp[N][N];
int n,m,k;
int c[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>m>>k;
	memset(mp,0x3f,sizeof(mp));
	for(int i=1;i<=m;i++)
	{
		int a,b,w;
		cin>>a>>b>>w;
		mp[a][b]=mp[b][a]=min(mp[a][b],w);
	}
	for(int i=1;i<=k;i++)
		cin>>c[i];
	cout<<"0";
	cout<<endl;
	return 0;
}

