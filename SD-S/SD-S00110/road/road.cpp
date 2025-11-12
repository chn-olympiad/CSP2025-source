#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
inline int read()
{
	int s=0;char c=getchar();bool f=0;
	for(;!isdigit(c);c=getchar())f|=(c=='-');
	for(;isdigit(c);c=getchar())s=(s<<1)+(s<<3)+(c^48);
	return f?-s:s;
}
const int mod=1e9+7;
inline int qpow(int x,int p)
{
	int res=1;
	while(p)
	{
		if(p&1)res=1ll*x*res%mod;
		x=1ll*x*x%mod;
		p>>=1;
	}
	return res;
}
const int N=1e4+7;
const int M=1e6+7;
//w<=1e9 long long!
int n,m,k;
int c[17],a[17][N],fa[N+10],tot;
ll ans,res;
bool vis[17];
struct Node{
	int x,y;
	ll w;
	bool operator <(const Node &B)const
	{
		return w<B.w;
	}
};
vector<Node> vec,v;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void merge(int x,int y)
{
	fa[find(x)]=fa[find(y)];
}
inline void krus()
{
	for(int i=1;i<=n+k;i++)fa[i]=i;
	sort(vec.begin(),vec.end());
	tot=n;
	for(Node e:vec)
	{
		if(tot<=1)break;
		if(find(e.x)!=find(e.y))
		{
			ans+=e.w;
			merge(e.x,e.y);
			tot--;
		}
	}
	printf("%lld",ans);
}
inline void kruspro()
{
	for(int i=1;i<=n+k;i++)fa[i]=i;
	sort(v.begin(),v.end());
	tot=n;
	for(Node e:v)
	{
		if(tot<=1)break;
		if(find(e.x)!=find(e.y))
		{
			res+=e.w;
			if(res>ans)break;
			merge(e.x,e.y);
			tot--;
		}
	}
	ans=min(res,ans);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	int x,y,z;
	for(int i=1;i<=m;i++)
		x=read(),y=read(),z=read(),
		vec.pb(Node{x,y,(long long)z});
	bool flag=0;
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		flag|=(c[i]>0);
		for(int j=1;j<=n;j++)
			a[i][j]=read();
		if(c[i]==0)
		{
			for(int j=1;j<=n;j++)
				for(int q=j+1;q<=n;q++)
					vec.pb(Node{j,q,(ll)a[i][j]+(ll)a[i][q]});
		}
	}
	if(!flag)
	{
		krus();
	}
	else
	{
		ans=0x3f3f3f3f3f3f3f3f;
		v=vec;
		kruspro();
		for(int s=(1<<k)-1;s>0;s--)
		{
			v=vec;
			res=0;
			for(int i=1;i<=k;i++)
			{
				if((1<<(i-1))&s)
				{
					res+=c[i];
					for(int j=1;j<=n;j++)
						for(int q=j+1;q<=n;q++)
							v.pb(Node{j,q,(ll)a[i][j]+(ll)a[i][q]});
				}
			}
			kruspro();
		}
		printf("%lld",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

