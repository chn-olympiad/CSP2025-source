#include <bits/stdc++.h>
using namespace std;

struct node
{
	int fr,to,nx,va,p;
	bool operator < (const node &a)const
	{
		return a.va < a;
	}
}e[400010];
int n,m,k;
int h1[100010],h[100010];
int c[20][20100];
int cnt1 = 0,cnt = 0;
periorty_queue<node> q;
int fa[200010];
int find(int x)
{
	if(x==fa[x])
		return x;
	else
		return fa[x] = find(fa[x]);
}
int kr(int x)
{
	for(int i =1 i<=x;i++)
	{
		fa[i] = i;
	}
	for(int i = 1; i <= cnt;i++)
	{
		q.push(e[i]);
	}
	int ct = 0;res = 0;
	while(ct<(x-1))
	{
		node x = q.top();
		
	}
}
void f(int u,int v,int w)
{
	cnt++;
	e[cnt] = 
}
void fc(int x)
{
	for(int i = 1;i <= n;i++)
	{
		f(x,i,mp[]);
		f(x,i,mp[]);
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1; i<=n;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		f(u,v,w);
		f(v,u,w);
	}
	cnt1 = cnt;
	
	for(int i = 1;i <= k;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			cin >> mp[i][j];
		}
	}
	
	int ans=999999999999;
	int kkk = pow(2,k)-1;
	for(int i =1 ;i <= kkk;i++)
	{
		int sum = 0;
		cnt = cnt1;
		int ct1=0,ct=0;
		int zt = i;
		while(i > 0)
		{
			ct++;
			if(i&1)
			{
				sum += fz(ct);
				fc(ct);
				ct1++;
			}
			
		}
		ans = min(ans,kr(n+ct1)+sum);
		cout << ans;
	}
	return 0;
}
