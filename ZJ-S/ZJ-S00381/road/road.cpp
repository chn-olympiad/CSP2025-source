#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 10100;
const int MAXM = 1100100;
const ll INF = 1e18;

int read()
{
	int f = 1,res = 0;
	char c;
	while(c < '0' || c > '9')
	{
		c = getchar();
		if(c == '-') f = -1;
	}
	while('0' <= c && c <= '9')
	{
		res = res * 10 + (c - '0');
		c = getchar();
	}
	return f * res;
}

int n,m,k,cnt;
int f[MAXN],head[MAXN];

//struct Edge
//{
//	int u,v;
//	ll w;
//	int nxt;
//}e[MAXM * 2];

struct simplE
{
	int u,v;
	ll w;
};

vector<simplE> se;

bool cmp(simplE a,simplE b)
{
	return a.w < b.w;
}

//void add(int u,int v,ll w)
//{
//	e[++cnt].u = u;
//	e[cnt].v = v;
//	e[cnt].w = w;
//	e[cnt].nxt = head[u];
//	head[u] = cnt;
//}

//vector<Edge> G[MAXN];

struct Vil
{
	int cost;
	int wei[MAXN];
}vil[15];

void init()
{
	for(int i = 1;i <= n + k + 10;i++)
		f[i] = i;
}

int getf(int u)
{
	if(u == f[u]) return u;
	return f[u] = getf(f[u]);
}

void merge(int u,int v)
{
	u = getf(u);
	v = getf(v);
	if(u != v) f[v] = u;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	n = read();
	m = read();
	k = read();
	
	se.resize(m + k * n + 100);
	
	for(int i = 1;i <= m;i++)
	{
		int u,v;
		ll w;
		u = read();
		v = read();
		w = read();
//		add(u,v,w);
//		add(v,u,w);
		se[i] = (simplE){u,v,w};
	}
	//////////////////////////////
//	for(int i = 1;i <= n;i++)
//		for(int j = head[i];j;j = e[j].nxt)
//			fprintf(stderr,"%d ---%lld---> %d\n",e[j].u,e[j].w,e[j].v);
	//////////////////////////////
	
	
	for(int i = 1;i <= k;i++)
	{
		vil[i].cost = read();
		for(int j = 1;j <= n;j++)
			vil[i].wei[j] = read();
	}	
	
	if(k == 0)
	{
		init();
		sort(se.begin() + 1,se.begin() + 1 + m,cmp);
		int cnt = 0;
		ll sum = 0;
		for(int i = 1;i <= m;i++)
		{
			if(cnt == n - 1) break;
			int u = se[i].u,v = se[i].v;
			ll w = se[i].w;
			if(getf(u) == getf(v)) continue;
			cnt++;
			sum += w;
			merge(u,v);
		}
		printf("%lld",sum);
		return 0;
	}
	else
	{
		ll ans = INF;
		int full = (1 << k) - 1;
		for(int mask = 0;mask <= full;mask++)
		{
			ll sum = 0;
			vector<simplE> se2;
			se2 = se;
			int ptr = m + 1;
			int usk = 0;
			
			for(int i = 1;i <= k;i++)
			{
				if((1 << (i - 1)) & mask)
				{
					usk++;
					sum += vil[i].cost;
					for(int j = 1;j <= n;j++)
					{
						se2[ptr].u = n + i;
						se2[ptr].v = j;
						se2[ptr].w = vil[i].wei[j];
						ptr++;
					}
				}
			}
			
//			printf("mask %d \n",mask);
//			for(int pp = 1;pp < ptr;pp++)
//				printf("%d ---%lld---> %d\n",se2[pp].u,se2[pp].w,se2[pp].v);
//			printf("\n");

//			///////////
//			fprintf(stderr,"base:sum = %lld,totnode = %d\n",sum,n + usk);
//			///////////

			init();
			sort(se2.begin() + 1,se2.begin() + ptr,cmp);
			int cnt = 0;
			for(int i = 1;i < ptr;i++)
			{
				if(cnt == n + usk - 1)
				{
//					//////////
//					cerr<<cnt<<" == "<<n + usk - 1<<"\n";
//					//////////
					break;	
				}
				
				int u = se2[i].u,v = se2[i].v;
				ll w = se2[i].w;
				if(getf(u) == getf(v)) continue;
				
			
				
				cnt++;
				sum += w;
				
//				///////////
//				fprintf(stderr,"using u = %d,v = %d,w = %lld,previus cnt = %d\n",u,v,w,cnt);
//				///////////
				
				merge(u,v);
			}
			
//			////////
//			fprintf(stderr,"\n");
//			////////
			
			ans = min(ans,sum);

		}
		
		printf("%lld",ans);
		
	}
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
