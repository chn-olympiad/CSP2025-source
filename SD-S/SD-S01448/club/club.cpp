#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>
#include <set>

#define int long long
#define endl "\n"
#define lowbit(x) x&-x;

using namespace std;
const int N=1e5+10;
int n,a[N][3],g[N];
int getnext(int x)
{
	if(g[x]==1) return max(a[x][2],a[x][3]);
	else if(g[x]==2) return max(a[x][1],a[x][3]);
	else return max(a[x][1],a[x][2]);
}
bool cmp(int x,int y)
{
	return (a[x][g[x]]-getnext(x))<(a[y][g[y]]-getnext(y));
}
void solve()
{
	cin>>n;
	vector<int> g1,g2,g3;
	int ans=0;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		int maxn=max({a[i][1],a[i][2],a[i][3]});
		if(maxn==a[i][1]) g1.push_back(i);
		else if(maxn==a[i][2]) g2.push_back(i);
		else g3.push_back(i);
		ans+=maxn;
	}
	for(int i:g1) g[i]=1;
	for(int i:g2) g[i]=2;
	for(int i:g3) g[i]=3;
	if(g1.size()>(n/2))
	{
		
		sort(g1.begin(),g1.end(),cmp);
		for(int i=0;i<(g1.size()-(n/2));i++) 
		{
			int x=g1[i];
			ans=(ans-(a[x][g[x]]-getnext(x)));
		}
	 } 
	else if(g2.size()>(n/2))
	{
		sort(g2.begin(),g2.end(),cmp);
		for(int i=0;i<(g2.size()-(n/2));i++) 
		{
			int x=g2[i];
			ans=(ans-(a[x][g[x]]-getnext(x)));
		}
	}
	else if(g3.size()>(n/2))
	{
		sort(g3.begin(),g3.end(),cmp);
		for(int i=0;i<(g3.size()-(n/2));i++) 
		{
			int x=g3[i];
			ans=(ans-(a[x][g[x]]-getnext(x)));
		}
	}
	cout<<ans<<endl;
	return;
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}

