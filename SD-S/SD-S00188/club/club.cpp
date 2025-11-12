#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e5+9;
struct heap{
	struct Hement{
		int w,x,op,g;
	}G[N<<1|1];int top;
	inline void ins(int w,int x,int op,int g);
	inline void dec();
	inline Hement pop();
}hs[5];int cnt[5],vis[N],a[N][5];
int T,n;ll ans;

/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

18
4
13
*/

inline int  read();

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	freopen("club5.in","r",stdin);
//	freopen("club5.out","w",stdout);
	
	scanf ("%d",&T);
	
	while (T-->0)
	{
		cnt[1]=cnt[2]=cnt[3]=0,ans=0;
		for (int i=1;i<=3;i++)
			while (hs[i].top)
				hs[i].dec();
		
		scanf ("%d",&n);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=3;j++)
				a[i][j]=read(),vis[i]=0;
		
		int A,B;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=3;j++)
				while (hs[j].top and vis[hs[j].pop().w]!=hs[j].pop().g)
					hs[j].dec();
			
			A=0,B=0;a[i][0]=-1;
			for (int j=1;j<=3;j++)
			{
				if (a[i][j]>a[i][A])
					B=A,A=j;
				else if (a[i][j]>a[i][B])
					B=j;
			}
			
			if (cnt[A]+1<=n/2)
			{
				cnt[A]++,vis[i]=A,ans+=a[i][A];
				for (int j=1;j<=3;j++)
					if (j!=A)
						hs[A].ins(i,a[i][j]-a[i][A],j,A);
			}
			else//注意到已经有一个满员，所以其他不会出堆 
			{
				if (hs[A].pop().x+a[i][A]>=a[i][B])
				{
					ans+=hs[A].pop().x+a[i][A];
					vis[hs[A].pop().w]=hs[A].pop().op;
					hs[A].dec();
					
					vis[i]=A;
					for (int j=1;j<=3;j++)
						if (j!=A)
							hs[A].ins(i,a[i][j]-a[i][A],j,A);
				}
				else
					ans+=a[i][B];
			}
		}
		
		printf ("%lld\n",ans);
	}
	
	return 0;
}

inline int read()
{
	int o=0,c=0,g=0;
	while (c<'0' or c>'9')
		g=(c=='-'),c=getchar();
	while (c>='0' and c<='9')
		o=(o<<1)+(o<<3)+(c^48),c=getchar();
	return (!g)?o:-o;
}

inline void heap::ins(int w,int x,int op,int g)
{
	G[++top]={w,x,op,g};
	
	int dw=top;
	while (dw/2)
	{
		if (G[dw/2].x<G[dw].x)
			swap(G[dw/2],G[dw]),dw=dw/2;
		else
			break;
	}
}

inline void heap::dec()
{
	swap(G[1],G[top]),G[top--]={0,0,0,0};
	
	int dw=1,rs;
	while (dw*2<=top)
	{
		rs=(dw*2+1<=top and G[dw*2+1].x>G[dw*2].x)?(dw*2+1):(dw*2);
		if (G[dw].x<G[rs].x)
			swap(G[dw],G[rs]),dw=rs;
		else
			break;
	}
}

inline heap::Hement heap::pop()
{
	return G[1];
}

