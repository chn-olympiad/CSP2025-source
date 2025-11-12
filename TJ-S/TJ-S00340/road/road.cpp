//mycode zyc
#include<bits/stdc++.h>
int n,m,k;
int u[10004],v[10005],w[10005];
vector<int>a[100005];
int ans=0;
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		a[u[i]].push_back(v[i]);
		a[v[i]].push_back(u[i]);
		ans+=w[i];
	}
	cout<<ans;
	return 0;
}
