#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,a[maxn][3],o[maxn],ans;
struct node
{
	int u,w;
};
vector<node> g[3];
bool cmp(node x,node y)
{
//	cout<<x.u<<" "<<y.u<<"\n";
	return x.w-a[x.u][o[x.u]]>y.w-a[y.u][o[y.u]];
}
void solve()
{
	ans=0;
	for(int i=0;i<3;i++)
	{
		g[i].clear();
	}
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int t=-1,op,s=-1;
		for(int j=0;j<=2;j++)
		{
			cin>>a[i][j];
			if(a[i][j]>t)
			{
				o[i]=op;
				op=j;
				s=t;
				t=a[i][j];
			}
			else if(a[i][j]>s)
			{
				o[i]=j;
				s=a[i][j];
			}
		}
		g[op].push_back({i,a[i][op]});
	}
	int t=0,st;
	for(int j=0;j<=2;j++)
	{
		if(g[j].size()>t)
		{
			st=j;
			t=g[j].size();
		}
	}
	
	if(g[st].size()>n/2)
	{
		sort(g[st].begin(),g[st].end(),cmp);
		
		for(int i=g[st].size()-1;i>=n/2;i--)
		{
			
			g[o[g[st][i].u]].push_back({g[st][i].u,a[g[st][i].u][o[g[st][i].u]]});
			g[st][i].w=-114;
		}
	}
	for(int i=0;i<3;i++)
	{
		for(auto v:g[i])
		{
			if(v.w<0) break;
			ans+=v.w;
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
