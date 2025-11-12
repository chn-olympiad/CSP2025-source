#include<bits/stdc++.h>
using namespace std;
#define max(a,b) ((a>b)?a:b)
const int maxn=1e5+5;
int read()
{
	int ans=0;
	char c=getchar();
	while(c>'9'||c<'0')
		c=getchar();
	while(c>='0'&&c<='9')
	{
		ans=(ans<<1)+(ans<<3)+c-48;
		c=getchar();
	}
	return ans;
}
int T;
int n,a[4][maxn],siz[3];
struct node{
	int id,val,chs;
	bool operator<(const node &b)const{
		return val<b.val;
	}
};
priority_queue<node> q[3];
int findMax(int x)
{
	int mx=0;
	for(int j=1;j<=3;j++)
	{
		if(a[j][x]>a[mx][x])
			mx=j;
	}
	return mx;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--)
	{
		for(int j=0;j<=2;j++)
		{
			siz[j]=0;
			while(!q[j].empty())
				q[j].pop();
		}
		n=read();
		for(int i=1;i<=n;i++)
		{
			a[0][i]=-1;
			for(int j=1;j<=3;j++)
			{
				a[j][i]=read();
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int tmp=findMax(i);
			int mxx=-0x3f3f3f3f;
			for(int j=1;j<=3;j++)
			{
				if(j==tmp)
					continue;
				mxx=max(mxx,a[j][i]-a[tmp][i]);
			}
			q[tmp-1].push({i,mxx,tmp});
			ans+=a[tmp][i];
			siz[tmp-1]++;
			if(siz[tmp-1]>(n>>1))
			{
				node u=q[tmp-1].top();
				q[tmp-1].pop();
				siz[tmp-1]--;
				ans-=a[u.chs][u.id];
				int mx=u.chs,nowmx=0;
				for(int j=1;j<=3;j++)
				{
					if(j==mx)
						continue;
					if(a[j][u.id]>a[nowmx][u.id])
						nowmx=j;
				}
				//cout<<i<<endl;
				//	cout<<u.id<<" "<<max(a[1][u.id]-a[nowmx][u.id],max(a[2][u.id]-a[nowmx][u.id],a[3][u.id]-a[nowmx][u.id]))<<" "<<nowmx<<endl;
				if(siz[nowmx-1]>=(n>>1))
					continue;
				mxx=-0x3f3f3f3f;
				for(int j=1;j<=3;j++)
				{
					if(j==tmp)
						continue;
					mxx=max(mxx,a[j][i]-a[tmp][i]);
				}
				q[nowmx-1].push({u.id,mxx,nowmx});
				ans+=a[nowmx][u.id];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
