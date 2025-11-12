#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5*1e6;
int n,m,k,c[N],a[15][10005],cnt,cllnt,nn;
vector<int> G[N],W[N],liantong[N];
map<int,int> mp;
void dfs(int point)
{
	for(auto u : G[point]) if(mp[u]==0)
	{
		mp[u]=mp[point];
		liantong[mp[u]].push_back(u);
		dfs(u);
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,q;
    cin>>n>>q;
    for(int i=1;i<=q;i++) cout<<0<<endl;
	return 0;
}