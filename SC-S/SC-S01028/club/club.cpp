#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define mod 1000000007
#define pii pair<int,int>
using namespace std;

inline int read()
{
	int x=0,f=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f?-x:x;
}
int t;
int n;

struct sd{
	int a[5];
	int maxx=-1e9;
	int cha;
}q[maxn],q1[maxn],q2[maxn],q3[maxn];
int tot1,tot2,tot3;
bool cmp(sd x,sd y)
{
	return x.cha<y.cha;
}
ll ans=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--)
	{
		tot1=tot2=tot3=0;
		ans=0;
		n=read();
		for(int i=1;i<=n;i++)
		{
			int x=read(),y=read(),z=read();
			q[i].a[1]=x;
			q[i].a[2]=y;
			q[i].a[3]=z;
			q[i].maxx=max(x,max(y,z));
		}
		for(int i=1;i<=n;i++)
		{
			ans+=q[i].maxx;
			if(q[i].a[1]==q[i].maxx) q1[++tot1]=q[i];
			else if(q[i].a[2]==q[i].maxx) q2[++tot2]=q[i];
			else if(q[i].a[3]==q[i].maxx) q3[++tot3]=q[i];
		}
		if(tot1>(n/2))
		{
			for(int i=1;i<=tot1;i++)
			{
				q1[i].cha=q1[i].a[1]-max(q1[i].a[2],q1[i].a[3]);
			}
			sort(q1+1,q1+tot1+1,cmp);
			for(int i=1;i<=tot1-n/2;i++)
			{
				ans-=q1[i].cha;
			}
		}
		else if(tot2>(n/2))
		{
			for(int i=1;i<=tot2;i++)
			{
				q2[i].cha=q2[i].a[2]-max(q2[i].a[1],q2[i].a[3]);
			}
			sort(q2+1,q2+tot2+1,cmp);
			for(int i=1;i<=tot2-n/2;i++)
			{
				ans-=q2[i].cha;
			}
		}
		else if(tot3>(n/2))
		{
			for(int i=1;i<=tot3;i++)
			{
				q3[i].cha=q3[i].a[3]-max(q3[i].a[1],q3[i].a[2]);
			}
			sort(q3+1,q3+tot3+1,cmp);
			for(int i=1;i<=tot3-n/2;i++)
			{
				ans-=q3[i].cha;
			}
		}
		cout<<ans<<'\n';
	}
}