#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=100005;
struct no{
	int w,id;
	bool operator < (const no b) const{
		return w<b.w;
	}
}p;
struct cmp{
	int id,w;
	bool operator < (const cmp c) const{
		return w<c.w;
	}
}b[4];
int a[N][4],s[4];
priority_queue<no>q[4];
inline int find(int i)
{
	if(a[i][1]>a[i][2])
	{
		if(a[i][1]>a[i][3])
			return 1;
		//1<=3
		return 3;
	}
	else//1<=2
	{
		if(a[i][2]>a[i][3])
			return 2;
		//2<=3
		return 3;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,i,n,j,k,l;
	ll ans;
	bool A,B,flag;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
		ans=0;
		s[1]=s[2]=s[3]=0;
		while(q[1].size())
			q[1].pop();
		while(q[2].size())
			q[2].pop();
		while(q[3].size())
			q[3].pop();
		flag=0;
		for(i=1;i<=n;i++)
		{
			b[1].id=1;
			b[1].w=a[i][1];
			b[2].id=2;
			b[2].w=a[i][2];
			b[3].id=3;
			b[3].w=a[i][3];
			sort(b+1,b+1+3);
			j=b[3].id;
			if(s[j]>=(n>>1))
			{
				p=q[j].top();
				if(p.w+a[i][j]>b[2].w)
				{
					ans+=p.w+a[i][j];
					q[j].pop();
				}
				else
				{
					j=b[2].id;
					s[j]++;
					ans+=a[i][j];
				}
			}
			else
			{
				s[j]++;
				ans+=a[i][j];
			}
			if(flag)
				continue;
			p.id=i;
			p.w=-1e9;
			for(k=1;k<=3;k++)
			{
				if(k==j)
					continue;
				p.w=max(p.w,a[i][k]-a[i][j]);
			}
			q[j].push(p);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
