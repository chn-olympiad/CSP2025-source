#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll qr()
{
	ll flag=1,sum=0;
	char ch=getchar();
	for(;!isdigit(ch);flag=(ch=='-')?-1:1,ch=getchar());
	for(;isdigit(ch);sum=sum*10+ch-'0',ch=getchar());
	return flag * sum;
}
ll n,m,k,cnt,ans;
struct eg{
	ll v,w;
	bool operator < (const eg x)const{return w>x.w;}
};
vector <eg> g[10002];
ll a[12][100002],c[12],son[10002];
bool vis[10002];
void addedge(ll u,ll v,ll w)
{
	g[u].push_back({v,w});
	g[v].push_back({u,w});
	son[u]++,son[v]++;
	return ;
}
void solve(ll x)
{
	priority_queue<eg> que;
	ll i,j;
	while(cnt<n)
	{
		for(i=0;i<son[x];i++)
		{
			ll v=g[x][i].v;
			if(vis[v])  continue;
			que.push(g[x][i]);
		}
		while(!que.empty())
		{
			eg e=que.top();
			if(vis[e.v])  que.pop();
			else
			{
				vis[e.v]=1;
//				cout<<e.v<<" "<<e.w<<endl;
				cnt++;ans+=e.w;x=e.v;
				que.pop();
				break;
			}
		}
	}
	return ;
}
int main()
{
	ll i,j;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=qr(),m=qr(),k=qr();
	for(i=1;i<=m;i++)
	{
		ll u,v,w;
		u=qr(),v=qr(),w=qr();
		addedge(u,v,w);
	}
	for(i=1;i<=k;i++)
	{
		c[i]=qr();
		for(j=1;j<=n;j++)  a[i][j]=qr();
	}
	cnt=1,vis[1]=1;
	solve(1);
	cout<<ans;
	return 0;
}
//test1
//6 6 0
//1 2 1
//2 3 3
//3 4 6
//4 5 5
//5 6 4
//1 6 2
//ans=15
//
//test2
//6 7 0
//1 2 1
//2 3 2
//3 4 8
//4 5 5
//5 1 7
//6 5 2
//1 6 4
//ans=14
