#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>

ll final;

inline int read()
{
	int x = 0,f = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0')
	{
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x<<3)+(x<<1) + ch-'0';
		ch = getchar();
	}
	return x*f;
}


const int N = 1e4+55,M = 1e6+15;

struct Edge{
	int u,v,w;
	inline bool operator<(const Edge& b)const
	{
		return w < b.w;
	}
}input[M],arr[(N<<3)+(N<<2)];
int cnts;

int n,m,k;

int fa[N];
int val[20];

inline int findf(int x)
{
	return fa[x] == x?x:fa[x] = findf(fa[x]);
}

void kru1()
{
	int cntk = 0;
	for(register int i = 1;i<=n;i++)
	{
		fa[i] = i;
	}
	for(register int i = 1;i<=m;i++)
	{
		int u = findf(input[i].u),v = findf(input[i].v);
		if(u != v)
		{
			fa[u] = v;
			arr[++cnts] = {input[i].u,input[i].v,input[i].w};
			++cntk;
			final += 1ll*input[i].w;
		}
		if(cntk == n-1)return;
	}
}

int vis[20];
int cntk;

int kru2(int cntt)
{
	cntk = 0;
	for(register int i = 1;i<=n+k;i++)
	{
		fa[i] = i;
	}
	ll ans = 0;
	int u,v;
	for(register int i = 1;i<=cnts;i++)
	{
		if((arr[i].u > n && vis[arr[i].u-n] == 0) ||
		   (arr[i].v > n && vis[arr[i].v-n] == 0))
		   	continue;
		
		u = findf(arr[i].u),v = findf(arr[i].v);
		
		if(u != v)
		{
			fa[u] = v;
			ans += 1ll*arr[i].w;
			cntk++;
		}
		if(cntk == cntt+n-1)return ans;
	}
	return ans;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	n = read(),m = read(),k = read();
	for(register int i = 1;i<=m;i++)
	{
		input[i].u = read(),input[i].v = read(),input[i].w = read();
	}

	sort(input+1,input+1+m);

	kru1();
	
//	cout<<final<<endl;
	
	int ww;
	for(register int i = 1;i<=k;i++)
	{
		val[i] = read();
		for(int j = 1;j<=n;j++)
		{
			ww = read();
			arr[++cnts] = {j,i+n,ww};
		}
	}
	
	sort(arr+1,arr+1+cnts);
	
	ll pres,cntc,v;
	for(register int i = 1;i<(1<<k);i++)
	{
		pres = cntc = 0;
		for(register int j = 1;j<=k;j++)
		{
			if((1<<(j-1))&i)vis[j] = 1,cntc++,pres+=val[j];
			else vis[j] = 0;
		}
		
		v = kru2(cntc);
//		cout<<i<<' '<<v+pres<<endl;
		final = min(final,v+pres);
	}
	
	cout<<final<<'\n';
	return 0;
 }
