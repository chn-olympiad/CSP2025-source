#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e5+7;
struct node{
	int x,y,z;
	int minx,midd,maxx;
}p[N];
int cnt[4];
int calc(int num,int xx)
{
	if(xx==p[num].x)return 1;
	if(xx==p[num].y)return 2;
	return 3;
}
bool cmp1(node a,node b)
{
	if(a.maxx!=b.maxx)return a.maxx>b.maxx;	
	if(a.midd!=b.midd)return a.midd>b.midd;
	else return a.minx>b.minx;
}
int T,n,s1[N],s2[N];
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x*f;
} 
 
void write(int x)
{
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	multiset<pair<int,int> > st[4];
	while(T--)
	{
		n=read();
		for(int i=1;i<=3;i++)st[i].clear(),cnt[i]=0;
		memset(p,0,sizeof(p));
		for(int i=1;i<=n;i++)
		{
			p[i].x=read();
			p[i].y=read();
			p[i].z=read();
			p[i].maxx=max(p[i].x,max(p[i].y,p[i].z));
			p[i].minx=min(p[i].x,min(p[i].y,p[i].z));
			p[i].midd=p[i].x+p[i].y+p[i].z-p[i].maxx-p[i].minx;
		}
		sort(p+1,p+n+1,cmp1);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int pos=calc(i,p[i].maxx);
			if(cnt[pos]==n/2)
			{
				int sum=0,sumid=-1;
				for(auto pp:st[pos])
				{
					int id=pp.first;
					int val=pp.second;
					if(val+p[i].midd<p[i].maxx+p[id].midd&&sum<p[i].maxx+p[id].midd-val)
					{
						sum=p[i].maxx+p[id].midd-val;
						sumid=id;
					}
				}
				if(sumid==-1)
				{
					ans+=p[i].midd;
					cnt[calc(i,p[i].midd)]++;
				}
				else
				{
					ans+=sum;
					st[pos].erase({sumid,p[sumid].maxx});
					st[pos].insert({i,p[i].maxx});
					st[calc(sumid,p[sumid].midd)].insert({sumid,p[sumid].midd});
					cnt[calc(sumid,p[sumid].midd)]++;
				}
			}
			else
			{
				cnt[pos]++;
				st[pos].insert({i,p[i].maxx});
				ans+=p[i].maxx;
			}
		}
		write(ans);
		puts("");
	}
	return 0;
}

