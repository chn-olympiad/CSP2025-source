#include <bits/stdc++.h>
using namespace std;
#define int long long int
struct node
{
	int like1;
	int like2;
	int like3;
	int val;
	int maxval;
};
const int maxn=1e5+5;
node a[maxn];
int top1;
int top2;
int top3;
bool cmp(node x,node y)
{
	return x.val>y.val||(x.val==y.val&&x.maxval>y.maxval);
}
int T;
int ans=0;
int n;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
int fnle(int x,int y,int z)
{
	int maa=max(max(x,y),z);
	int mii=min(min(x,y),z);
	if(x!=maa)
	{
		if(x!=mii)
		{
			return x;
		}
	}
	if(y!=maa)
	{
		if(y!=mii)
		{
			return y;
		}
	}
	if(z!=maa)
	{
		if(z!=mii)
		{
			return z;
		}
	}
}
signed main ()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();
		top1=top2=top3=0;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			a[i].like1=read();
			a[i].like2=read();
			a[i].like3=read();
			//cin>>a[i].like1>>a[i].like2>>a[i].like3;
			a[i].maxval=max(max(a[i].like1,a[i].like2),a[i].like3);
			
			a[i].val=a[i].maxval-fnle(a[i].like1,a[i].like2,a[i].like3);
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			//cout<<a[i].like1<<" "<<a[i].like2<<" "<<a[i].like3<<"\n";
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i].maxval==a[i].like1)
			{
				if(top1<n/2)
				{
					top1++;
					ans+=a[i].maxval;
				}
				else if(a[i].like2>a[i].like3)
				{
					if(top2<n/2)
					{
						top2++;
						ans+=a[i].like2;
					}
					else if(top3<n/2)
					{
						top3++;
						ans+=a[i].like3;
					}
				}
				else
				{
					if(top3<n/2)
					{
						top3++;
						ans+=a[i].like3;
					}
					else if(top2<n/2)
					{
						top2++;
						ans+=a[i].like2;
					}
				}
			}
			else if(a[i].maxval==a[i].like2)
			{
				if(top2<n/2)
				{
					top2++;
					ans+=a[i].maxval;
				}
				else if(a[i].like1>a[i].like3)
				{
					if(top1<n/2)
					{
						top1++;
						ans+=a[i].like1;
					}
					else if(top3<n/2)
					{
						top3++;
						ans+=a[i].like3;
					}
				}
				else
				{
					if(top3<n/2)
					{
						top3++;
						ans+=a[i].like3;
					}
					else if(top2<n/2)
					{
						top2++;
						ans+=a[i].like2;
					}
				}
			}
			else
			{
				if(top3<n/2)
				{
					top3++;
					ans+=a[i].maxval;
				}
				else if(a[i].like2>a[i].like1)
				{
					if(top2<n/2)
					{
						top2++;
						ans+=a[i].like2;
					}
					else if(top3<n/2)
					{
						top3++;
						ans+=a[i].like3;
					}
				}
				else
				{
					if(top1<n/2)
					{
						top1++;
						ans+=a[i].like1;
					}
					else if(top1<n/2)
					{
						top1++;
						ans+=a[i].like1;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
