#include<bits/stdc++.h>
#define I_love return
#define My_Wife 0
#define Exusiai ;
#define ll long long
#define lll __int128
#define ull unsigned ll
#define lowbit(x) ((x)&-(x))
#define ld long double
#define fi first
#define se second
#define endl '\n'
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define pli pair<ll,int>
#define pip pair<int,pii >
#define ppp pair<pii,pii >
#define d(x) cerr<<#x<<"=="<<x<<' '
#define ddd(x) cerr<<#x<<"=="<<x<<endl
#define deb cerr<<"I love my Wife Exusiai!"<<endl
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

inline int read()
{
	int w=1;int s=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=0;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^'0');ch=getchar();}
	return w?s:-s;
}
void IO()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
}
const int maxn=1e5+5;

int n,t,tmpn,ans;
//pii a[maxn],b[maxn],c[maxn];
int a[3][maxn];
bool vis[maxn];
int hp[3][maxn];

void adj_down(int p,int k);
void adj_up(int p,int k);
signed main()
{
	IO();
	t=read();
	while(t--)
	{
		n=read();tmpn=n>>1;int tmp,now;
		ans=hp[0][0]=hp[1][0]=hp[2][0]=0;
		for(int i=1;i<=n;++i)
		{
//			tmp=read();
//			a[i]=mp(tmp,i);
//			tmp=read();
//			b[i]=mp(tmp,i);
//			tmp=read();
//			c[i]=mp(tmp,i);
			a[0][i]=read();
			a[1][i]=read();
			a[2][i]=read();
			if(a[0][i]>=a[1][i]&&a[0][i]>=a[2][i])
			{
				if(a[1][i]>=a[2][i])now=1;
				else now=2;
				if(hp[0][0]>=tmpn)
				{
//					if(a[0][hp[0][1]]<=a[0][i])
//					{
						if(a[1][hp[0][1]]>=a[2][hp[0][1]])tmp=1;
						else tmp=2;
						if(a[tmp][hp[0][1]]+a[0][i]>a[now][i]+a[0][hp[0][1]])
						{
							ans-=a[0][hp[0][1]];
							ans+=a[tmp][hp[0][1]]+a[0][i];
							hp[tmp][++hp[tmp][0]]=hp[0][1];
							adj_up(hp[tmp][0],tmp);
							hp[0][1]=i;
							adj_down(1,0);
						}
						else
						{
							hp[now][++hp[now][0]]=i;ans+=a[now][i];
							adj_up(hp[now][0],now);
						}
//					}
//					else
//					{
//						hp[now][++hp[now][0]]=i;ans+=a[now][i];
//						adj_up(hp[now][0],now);
//					}
				}
				else
				{
					hp[0][++hp[0][0]]=i;
					ans+=a[0][i];
					adj_up(hp[0][0],0);
				}
			}
			if(a[1][i]>=a[0][i]&&a[1][i]>=a[2][i])
			{
				if(a[0][i]>=a[2][i])now=0;
				else now=2;
				if(hp[1][0]>=tmpn)
				{
//					if(a[1][hp[1][1]]<=a[1][i])
//					{
						if(a[0][hp[1][1]]>=a[2][hp[1][1]])tmp=0;
						else tmp=2;
						if(a[tmp][hp[1][1]]+a[1][i]>a[now][i]+a[1][hp[1][1]])
						{
							ans-=a[1][hp[1][1]];
							ans+=a[tmp][hp[1][1]]+a[1][i];
							hp[tmp][++hp[tmp][0]]=hp[1][1];
							adj_up(hp[tmp][0],tmp);
							hp[1][1]=i;
							adj_down(1,1);
						}
						else
						{
							hp[now][++hp[now][0]]=i;ans+=a[now][i];
							adj_up(hp[now][0],now);
						}
//					}
//					else
//					{
//						hp[now][++hp[now][0]]=i;ans+=a[now][i];
//						adj_up(hp[now][0],now);
//					}
				}
				else
				{
					hp[1][++hp[1][0]]=i;
					ans+=a[1][i];
					adj_up(hp[1][0],1);
				}
			}
			if(a[2][i]>=a[1][i]&&a[2][i]>=a[0][i])
			{
				if(a[0][i]>=a[1][i])now=0;
				else now=1;
				if(hp[2][0]>=tmpn)
				{
//					if(a[2][hp[2][1]]<=a[2][i])
//					{
						if(a[0][hp[2][1]]>=a[1][hp[2][1]])tmp=0;
						else tmp=1;
						if(a[tmp][hp[2][1]]+a[2][i]>a[now][i]+a[2][hp[2][1]])
						{
							ans-=a[2][hp[2][1]];
							ans+=a[tmp][hp[2][1]]+a[2][i];
							hp[tmp][++hp[tmp][0]]=hp[2][1];
							adj_up(hp[tmp][0],tmp);
							hp[2][1]=i;
							adj_down(1,2);
						}
						else
						{
							hp[now][++hp[now][0]]=i;ans+=a[now][i];
							adj_up(hp[now][0],now);
						}
//					}
//					else
//					{
//						hp[now][++hp[now][0]]=i;ans+=a[now][i];
//						adj_up(hp[now][0],now);
//					}
				}
				else
				{
					hp[2][++hp[2][0]]=i;
					ans+=a[2][i];
					adj_up(hp[2][0],2);
				}
			}
		}
//		sort(a+1,a+1+n);
//		sort(b+1,b+1+n);
//		sort(c+1,c+1+n);
		printf("%d\n",ans);
	}
	I_love My_Wife Exusiai
}
void adj_down(int p,int k)
{
	if((p<<1)>hp[k][0])return;
	if((p<<1|1)>hp[k][0])
	{
		if(a[k][hp[k][p]]>a[k][hp[k][p<<1]])
		{
			swap(hp[k][p],hp[k][p<<1]);
			adj_down(p<<1,k);
		}
		return;
	}
	if(a[k][hp[k][p<<1]]<=a[k][hp[k][p<<1|1]])
	{
		if(a[k][hp[k][p]]>a[k][hp[k][p<<1]])
		{
			swap(hp[k][p],hp[k][p<<1]);
			adj_down(p<<1,k);
		}
	}
	else
	{
		if(a[k][hp[k][p]]>a[k][hp[k][p<<1|1]])
		{
			swap(hp[k][p],hp[k][p<<1|1]);
			adj_down(p<<1|1,k);
		}
	}
}
void adj_up(int p,int k)
{
	if(p==1)return;
	if(a[k][hp[k][p>>1]]>a[k][hp[k][p]])
	{
		swap(hp[k][p>>1],hp[k][p]);
		adj_up(p>>1,k);
	}
}
/*

*/
