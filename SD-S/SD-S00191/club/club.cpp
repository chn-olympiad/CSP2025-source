#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
inline ll read()
{
	ll x=0;
	ll f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	} 
	return f*x;
}

struct node{
	int bh;
	ll sz;
	bool operator<(const node &other) const
	{
		if(sz!=other.sz)
		return sz>other.sz;
		else
		return bh>other.bh;
	} 
}node[maxn][4],sum[maxn],maxnode[maxn];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=read();
	ll zg[maxn];
	
	while(t--)
	{
		ll n=read();
		for(int i=0;i<=n;i++)
		{
			zg[i]=n/2;
		}
		for(int i=1;i<=n;i++)
		{
			node[i][1].bh=1;
			node[i][1].sz=read();
			node[i][2].bh=2;
			node[i][2].sz=read();
			node[i][3].bh=3;
			node[i][3].sz=read();
			maxnode[i].sz=max(node[i][3].sz,max(node[i][1].sz,node[i][2].sz));
			if(maxnode[i].sz==node[i][1].sz)
			maxnode[i].bh=1;
			else
			if(maxnode[i].sz==node[i][2].sz)
			maxnode[i].bh=2;
			else
			maxnode[i].bh=3;
			sum[i].bh=i;
			sum[i].sz=node[i][1].sz+node[i][2].sz+node[i][3].sz-maxnode[i].sz;
		}
		for(int i=1;i<=n;i++)
		{
			sort(node[i]+1,node[i]+5);
		}
		sort(sum+1,sum+n+1);
		/*for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cout<<node[i][j].bh<<" "<<node[i][j].sz<<"||";
			}
			cout<<maxnode[i].sz<<"?";
			cout<<sum[i].bh<<' '<<sum[i].sz<<"\n";
		}*/
		ll ans=0;
			for(int i=n;i>=1;i--)
			{
				ll zdbh=sum[i].bh;
				for(int j=1;j<=3;j++)
				{
					if(zg[node[zdbh][j].bh]>0)
					{
						ans+=node[zdbh][j].sz;
						zg[node[zdbh][j].bh]--;
						break;
					}
				
				}
			}
		
		
		cout<<ans<<'\n';	
	}
	return 0;
}
