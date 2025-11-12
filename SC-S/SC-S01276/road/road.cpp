#include<bits/stdc++.h>
using namespace std;

void io()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
} 
const int maxn = 1e4+5;
int n,m,k,cf[15],af[15][maxn],f[maxn];
vector <pair< int,pair <int,int> > > G,T;
int find(int x)
{
	if(f[x] != x)
	{
		return f[x] = find(f[x]);
	}
	else return x;
}
void join(int x,int y)
{
	int a = find(x),b = find(y);
	f[a] = y;
}
signed main()
{
	io();
	cin >>n>>m>>k;
	for(int i = 1; i <= n; i++)f[i] = i;
	int a,b,c;
	for(int i = 1; i <= m; i++) 
	{
		cin >>a>>b>>c;
		G.push_back({c,{a,b}});
	}
	sort(G.begin(),G.end());
	int cnt = 0,tot = 0;
	for(auto e : G)
	{
		int a = e.second.first,b = e.second.second;
		if(find(a) != find(b))
		{
			T.push_back(e);
			join(a,b);
			tot+=e.first;
			cnt++;
		}
		if(cnt == n-1)break;
	}
	if(k == 0)
	{
		cout<<tot;
		return 0;
	}
	bool flag = 1;
	for(int i = 1; i <= k; i++)
	{
		cin >>cf[i];
		if(cf[i] != 0)flag = 0;
		for(int j = 1; j <= n; j++)cin>>af[i][j];
	}
	if(flag)
	{
		int ans = tot;
		map <pair<int,int>,bool> C;
		for(auto e : T)
	    {
	    	int minn = e.first,p = -1;
			int a = e.second.first,b = e.second.second;
			for(int i = 1; i <= k; i++)
			{
				int sum = 0;
				if(!C[{i,a}])sum+=af[i][a];
				if(!C[{i,b}])sum+=af[i][b];
				if(sum <= minn)
				{
					minn = sum;
					p = i;
				}
			}
			if(minn != e.first)
			{
			    ans+=((C[{p,a}])?0:af[p][a]);
			    ans+=((C[{p,b}])?0:af[p][b]);
				C[{p,a}] = 1;
			    C[{p,b}] = 1;
			    ans-=e.first;
			}
	    }
	    cout<<ans;
	    return 0;
	}
	else
	{
		int ans = tot;
		map <pair<int,int>,bool> C;
		map <int,bool> Q;
		for(auto e : T)
	    {
	    	int minn = e.first,p = -1;
			int a = e.second.first,b = e.second.second;
			for(int i = 1; i <= k; i++)
			{
				int sum = 0;
				if(!C[{i,a}])sum+=af[i][a];
				if(!C[{i,b}])sum+=af[i][b];
				if(sum <= minn)
				{
					minn = sum;
					p = i;
				}
			}
			if(minn != e.first)
			{
				if(!Q[p])ans+=cf[p];
				Q[p] = 1;
			    ans+=((C[{p,a}])?0:af[p][a]);
			    ans+=((C[{p,b}])?0:af[p][b]);
				C[{p,a}] = 1;
			    C[{p,b}] = 1;
			    ans-=e.first;
			}
	    }
	    cout<<min(ans,tot);
	    return 0;
	}
}