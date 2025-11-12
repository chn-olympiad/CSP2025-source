#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define itn int
#define ing int
#define endl '\n'
using namespace std;

/*
ll mi(ll a,ll b,ll c)
{
	ll ans=1;
	while(b>0)
	{
		if(b&1)
		{
			ans*=a;
		}
		ans%=c;
		a*=a;
		a%=c;
		b>>=1;
	}
	return ans;
}
*/
/*
bool cmp(int x,int y)
{
	return x>y;
}
*/

//int n,m;
const int N=1e6+5;

//vector<int>e[N];

//priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
int n,m,k;
struct node
{
	int u,v,w;
}e[N];
int f[10005];
long long ans;
int find(int u)
{
	if(f[u]==u)return u;
	else return f[u]=find(f[u]);
}
void mrg(int u,int v,int w)
{
	u=find(u);
	v=find(v);
	if(u==v)return;
	f[u]=v;
	ans+=w;
	return;
	
}
bool cmp(node x,node y)
{
	return x.w<y.w;
}
//void dfs(int step,int cnt)
//{
//	ans+= 
//}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	if(k==0)
	{
		for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
		
			}
			int x;
			
			for(int i=1;i<=k;i++)
			{cin>>x;
				for(int i=1;i<=n;i++)cin>>x;
			}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		mrg(e[i].u,e[i].v,e[i].w);
	}
	cout<<ans;
	}
	else 
	{
		for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
		
			}
			int money;
			int v;
			int it=m+1;
			int ob=-1;
			for(int i=1;i<=k;i++)
			{cin>>money;
			ans+=money;
				for(int i=1;i<=n;i++)
				{
					cin>>v;
					e[it].u=ob;
					e[it].v=i;
					e[it].w=v;
					it++;
					ob--;
				}
			}
		sort(e+1,e+m+k*n+1,cmp);
	for(int i=1;i<=m+k*n;i++)
	{
		mrg(e[i].u,e[i].v,e[i].w);
	}
	cout<<ans;
	}
	return 0;
}
