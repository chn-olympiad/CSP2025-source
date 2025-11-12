#include<bits/stdc++.h>
#include<bitset>
using namespace std;

typedef long long ll;

#define N 10005

void _sRuint(unsigned int&x)
{
	x=0;
	char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))
	{
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
}

void _sRint(int&x)
{
	bool f=false;
	x=0;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
		{
			f=true;
			break;
		}
		c=getchar();
	}
	while(isdigit(c))
	{
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	if(f)x=-x;
}

void _sWuint(unsigned int x)
{
	if(x>9)
	{
		_sWuint(x/10);
	}
	putchar(((x%10)^48));
}

void _sWint(int x)
{
	if(x<0)
	{
		x=-x;
		putchar('-');
	}
	_sWuint(x);
}

void _sRuint(unsigned long long&x)
{
	x=0;
	char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))
	{
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
}

void _sRll(long long&x)
{
	bool f=false;
	x=0;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
		{
			f=true;
			break;
		}
		c=getchar();
	}
	while(isdigit(c))
	{
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	if(f)x=-x;
}

void _sWull(unsigned long long x)
{
	if(x>9)
	{
		_sWull(x/10);
	}
	putchar(((x%10)^48));
}

void _sWll(long long x)
{
	if(x<0)
	{
		x=-x;
		putchar('-');
	}
	_sWull(x);
}

int n,m,k,u,v,w,now;

ll ans,ansf=(1ll<<63)-1;

short f[10015];

struct rod
{
	int u,v,w;
	void read()
	{
		_sRint(u);
		_sRint(v);
		_sRint(w);
		if(u>v)
		{
			swap(u,v);
		}
	}
	void wr()
	{
		_sWint(u);
		putchar(' ');
		_sWint(v);
		putchar(' ');
		_sWint(w);
		putchar(' ');
	}
	friend bool operator < (const rod x,const rod y)
	{
		return x.w!=y.w?x.w<y.w:(x.u!=y.u?x.u<y.u:x.v<y.v);
	}
	friend bool operator > (const rod x,const rod y)
	{
		return x.w!=y.w?x.w>y.w:(x.u!=y.u?x.u>y.u:x.v>y.v);
	}
}rx;

priority_queue<rod,vector<rod>,greater<rod> >r,r1;

struct rd
{
	int id,x;
	friend bool operator < (const rd x,const rd y)
	{
		return x.x!=y.x?x.x<y.x:x.id<y.id;
	}
}p;

vector<rd>g[N];

struct vi
{
	int c;
	rd d[N];
	void read()
	{
		_sRint(c);
		for(int i=1;i<=n;i++)
		{
			_sRint(d[i].x);
			d[i].id=i;
		}
		stable_sort(d+1,d+n+1);
	}
}a[15];

bitset<N>t[N];

bool kp[15];

void dfs(int step)
{
	if(step>k)
	{
		ans=0;
		memset(t,0,sizeof(t));
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n;j++)
//			{
//				cout<<t[i][j]<<" ";
//			}
//			cout<<"\n";
//		}
		memset(f,0,sizeof(f));
//		for(int i=1;i<=n;i++)cout<<f[i]<<" ";
//		cout<<"\n";
		r1=r;
		for(int i=1;i<=k;i++)
		{
			if(kp[i])
			{
				ans+=a[i].c;
				rx.v=n+i;
				for(int j=1;j<=n;j++)
				{
					rx.u=a[i].d[j].id;
					rx.w=a[i].d[j].x;
					r1.push(rx);
				}
			}
		}
//		while(r1.size())
//		{
//			rx=r1.top();
//			r1.pop();
//			rx.wr();
//			putchar('\n');
//		}
//		r1=r;
//		for(int i=1;i<=k;i++)
//		{
//			if(kp[i])
//			{
//				ans+=a[i].c;
//				rx.v=n+i;
//				for(int j=1;j<=n;j++)
//				{
//					rx.u=a[i].d[j].id;
//					rx.w=a[i].d[j].x;
//					r1.push(rx);
//				}
//			}
//		}
		while(r1.size())
		{
			rx=r1.top();
			r1.pop();
			if(!t[f[rx.u]][f[rx.v]])
			{
				ans+=rx.w;
				if(f[rx.u]>0&&f[rx.v]>0)
				{
					t[f[rx.u]][f[rx.v]]=t[f[rx.v]][f[rx.u]]=true;
					continue;
				}
				if(f[rx.u]==0&&f[rx.v]==0)
				{
					f[rx.u]=f[rx.v]=++now;
					t[now][now]=true;
					continue;
				}
				f[rx.u]=f[rx.v]=max(f[rx.u],f[rx.v]);
			}
		}
//		cout<<ans;
		ansf=min(ans,ansf);
//		_sWll(ans);
//		putchar('\n');
		return;
	}
	dfs(step+1);
	kp[step]=true;
	dfs(step+1);
	kp[step]=false;
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	_sRint(n);
	_sRint(m);
	_sRint(k);
	for(int i=1;i<=m;i++)
	{
		rx.read();
		r.push(rx);
	}
//	for(int i=1;i<=m;i++)
//	{
//		if(!t[f[r[i].u]][f[r[i].v]])
//		{
//			ans+=r[i].w;
//			if(f[r[i].u]>0&&f[r[i].v]>0)
//			{
//				t[f[r[i].u]][f[r[i].v]]=t[f[r[i].v]][f[r[i].u]]=true;
//				continue;
//			}
//			if(f[r[i].u]==0&&f[r[i].v]==0)
//			{
//				f[r[i].u]=f[r[i].v]=++now;
//				t[now][now]=true;
//				continue;
//			}
//			f[r[i].u]=f[r[i].v]=max(f[r[i].u],f[r[i].v]);
//		}
//	}
//	cout<<ans;
	for(int i=1;i<=k;i++)
	{
		a[i].read();
	}
	dfs(1);
	cout<<ansf;
	return 0;
}

